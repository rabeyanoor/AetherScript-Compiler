/* ══════════════════════════════════════════════════════════════════════════
   AetherScript IDE — app.js
   Handles: API calls, Token rendering, D3 AST tree, Console output
══════════════════════════════════════════════════════════════════════════ */

const API_BASE = 'http://localhost:8000';

// ── State ─────────────────────────────────────────────────────────────────
let currentZoom = 1;
let zoomBehavior = null;
let svgSelection = null;

// ── On Load: check backend health ────────────────────────────────────────
window.addEventListener('DOMContentLoaded', async () => {
  await checkHealth();
  // Set default code
  document.getElementById('code-editor').value =
`let x = 10;
let y = 5;
if (x > y) {
  print(x);
}`;
});

async function checkHealth() {
  try {
    const res = await fetch(`${API_BASE}/health`, { signal: AbortSignal.timeout(3000) });
    if (res.ok) {
      setStatus('connected', 'Backend Connected');
    } else {
      setStatus('error', 'Backend Error');
    }
  } catch {
    setStatus('error', 'Backend Offline');
    consolePrint('❌ Cannot reach backend at http://localhost:8000', 'error');
    consolePrint('   Run: ./start_backend.sh', 'info');
  }
}

function setStatus(state, text) {
  const dot  = document.getElementById('status-dot');
  const span = document.getElementById('status-text');
  dot.className  = `status-dot ${state}`;
  span.textContent = text;
}

// ── Compile ───────────────────────────────────────────────────────────────
async function runCompile() {
  const code = document.getElementById('code-editor').value.trim();
  if (!code) { consolePrint('⚠ No code to compile.', 'error'); return; }

  showLoading(true);
  clearConsole();
  clearAst();

  consolePrint('$ aetherscript compile …', 'prompt');

  try {
    const res = await fetch(`${API_BASE}/compile`, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ code }),
      signal: AbortSignal.timeout(10000),
    });

    const data = await res.json();

    if (data.success) {
      consolePrint(`✅ Compiled successfully. ${data.tokens.length} token(s) found.`, 'success');
      renderTokens(data.tokens);
      if (data.ast) {
        renderAstTree(data.ast);
        consolePrint('🌳 AST tree generated.', 'info');
      }
    } else {
      consolePrint(`❌ Compilation failed:`, 'error');
      if (data.error) {
        data.error.split('\n').forEach(l => consolePrint('   ' + l, 'error'));
      }
      renderTokens(data.tokens || []);
      consolePrint(`   Tokens lexed before error: ${(data.tokens||[]).length}`, 'info');
    }

  } catch (err) {
    consolePrint(`❌ Network error: ${err.message}`, 'error');
    setStatus('error', 'Backend Offline');
  } finally {
    showLoading(false);
  }
}

// ── Tokens ────────────────────────────────────────────────────────────────
function renderTokens(tokens) {
  const list = document.getElementById('token-list');
  list.innerHTML = '';
  if (!tokens.length) {
    list.innerHTML = '<span class="token-placeholder">No tokens</span>';
    return;
  }
  tokens.forEach(t => {
    const chip = document.createElement('span');
    chip.className = `token-chip ${t.type}`;
    chip.textContent = t.value;
    chip.title = t.type;
    list.appendChild(chip);
  });
}

// ── AST Tree (D3) ─────────────────────────────────────────────────────────
function flattenToD3(node, parentKey = null, nodes = [], links = []) {
  if (!node || typeof node !== 'object') return;

  const id = Math.random().toString(36).slice(2);
  const label = node.type || 'Node';
  const val   = node.value || null;

  nodes.push({ id, label, val });
  if (parentKey !== null) links.push({ source: parentKey, target: id });

  const children = [];
  if (node.left)  children.push(node.left);
  if (node.mid)   children.push(node.mid);
  if (node.right) children.push(node.right);
  if (node.next)  children.push(node.next);

  children.forEach(c => flattenToD3(c, id, nodes, links));
  return { nodes, links };
}

function astToHierarchy(node) {
  if (!node || typeof node !== 'object') return null;
  const label    = node.type || 'Node';
  const val      = node.value || null;
  const children = [];

  if (node.left)  { const c = astToHierarchy(node.left);  if (c) children.push(c); }
  if (node.mid)   { const c = astToHierarchy(node.mid);   if (c) children.push(c); }
  if (node.right) { const c = astToHierarchy(node.right); if (c) children.push(c); }
  if (node.next)  { const c = astToHierarchy(node.next);  if (c) children.push(c); }

  return { label, val, children: children.length ? children : undefined };
}

function renderAstTree(astJson) {
  const placeholder = document.getElementById('ast-placeholder');
  placeholder.classList.add('hidden');

  const container = document.getElementById('ast-container');
  const svg = d3.select('#ast-svg');
  svg.selectAll('*').remove();

  const W = container.clientWidth  || 600;
  const H = container.clientHeight || 400;

  // Setup zoom
  const g = svg.append('g');
  zoomBehavior = d3.zoom()
    .scaleExtent([0.1, 3])
    .on('zoom', e => g.attr('transform', e.transform));
  svg.call(zoomBehavior);
  svgSelection = svg;

  // Build hierarchy
  const root = astToHierarchy(astJson);
  const hierarchy = d3.hierarchy(root);
  const nodeCount = hierarchy.descendants().length;
  const nodeSpacingX = Math.max(70, 420 / (nodeCount + 1));
  const nodeSpacingY = 90;

  const treeLayout = d3.tree()
    .nodeSize([nodeSpacingX, nodeSpacingY]);

  treeLayout(hierarchy);

  // Center the tree
  const nodes = hierarchy.descendants();
  const xs = nodes.map(n => n.x);
  const ys = nodes.map(n => n.y);
  const minX = Math.min(...xs), maxX = Math.max(...xs);
  const minY = Math.min(...ys), maxY = Math.max(...ys);
  const treeW = maxX - minX + 120;
  const treeH = maxY - minY + 120;

  const initX = (W - treeW) / 2 - minX + 60;
  const initY = 50;

  svg.call(zoomBehavior.transform,
    d3.zoomIdentity.translate(initX, initY));

  // Links
  g.selectAll('.link')
    .data(hierarchy.links())
    .join('path')
    .attr('class', 'link')
    .attr('d', d3.linkVertical()
      .x(d => d.x)
      .y(d => d.y));

  // Nodes
  const node = g.selectAll('.node')
    .data(nodes)
    .join('g')
    .attr('class', d => `node ${d.data.label}`)
    .attr('transform', d => `translate(${d.x},${d.y})`);

  node.append('circle').attr('r', 22);

  // Type label
  node.append('text')
    .attr('class', 'node-type')
    .attr('dy', '0.35em')
    .attr('y', d => d.data.val ? -7 : 0)
    .attr('text-anchor', 'middle')
    .text(d => abbreviate(d.data.label));

  // Value label
  node.filter(d => d.data.val)
    .append('text')
    .attr('class', 'node-value')
    .attr('dy', '0.35em')
    .attr('y', 8)
    .attr('text-anchor', 'middle')
    .text(d => d.data.val);

  // Tooltip on hover (show full type)
  node.append('title').text(d =>
    d.data.val ? `${d.data.label}: ${d.data.val}` : d.data.label
  );
}

// Abbreviate long node type names for the circle
function abbreviate(label) {
  const map = {
    'Program':        'PROG',
    'VarDecl':        'VAR',
    'Assignment':     'ASGN',
    'IfStatement':    'IF',
    'WhileStatement': 'WHILE',
    'PrintStatement': 'PRINT',
    'BinaryExpression':'BIN OP',
    'Block':          'BLOCK',
    'Identifier':     'ID',
    'Literal':        'LIT',
    'ReturnStatement':'RET',
  };
  return map[label] || label.slice(0, 5).toUpperCase();
}

// ── Zoom Controls ─────────────────────────────────────────────────────────
function zoomIn() {
  if (svgSelection && zoomBehavior)
    svgSelection.transition().call(zoomBehavior.scaleBy, 1.3);
}
function zoomOut() {
  if (svgSelection && zoomBehavior)
    svgSelection.transition().call(zoomBehavior.scaleBy, 0.75);
}
function resetZoom() {
  if (svgSelection && zoomBehavior) {
    const container = document.getElementById('ast-container');
    svgSelection.transition().call(
      zoomBehavior.transform, d3.zoomIdentity.translate(container.clientWidth / 2, 50).scale(1)
    );
  }
}

// ── Console ───────────────────────────────────────────────────────────────
function consolePrint(text, cls = '') {
  const div = document.getElementById('console');
  const span = document.createElement('span');
  span.className = `console-line ${cls ? 'console-' + cls : ''}`;
  span.textContent = text;
  div.appendChild(span);
  div.scrollTop = div.scrollHeight;
}

function clearConsole() {
  document.getElementById('console').innerHTML = '';
}

// ── Helpers ───────────────────────────────────────────────────────────────
function clearAst() {
  d3.select('#ast-svg').selectAll('*').remove();
  document.getElementById('ast-placeholder').classList.remove('hidden');
  svgSelection = null;
}

function clearAll() {
  document.getElementById('code-editor').value = '';
  document.getElementById('token-list').innerHTML = '<span class="token-placeholder">Run code to see tokens…</span>';
  clearAst();
  clearConsole();
}

function showLoading(show) {
  document.getElementById('loading-overlay').classList.toggle('hidden', !show);
  document.getElementById('btn-run').disabled = show;
}

// Ctrl+Enter shortcut to run
document.addEventListener('keydown', e => {
  if ((e.ctrlKey || e.metaKey) && e.key === 'Enter') {
    e.preventDefault();
    runCompile();
  }
});
