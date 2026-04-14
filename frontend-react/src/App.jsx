import { useState, useCallback, useEffect } from "react";
import axios from "axios";
import EditorPanel from "./components/EditorPanel";
import TokenPanel from "./components/TokenPanel";
import ASTPanel from "./components/ASTPanel";
import OutputPanel from "./components/OutputPanel";

const SITE_THEMES = [
  { id: "dark", label: "🌙 Dark" },
  { id: "light", label: "☀️ Light" },
  { id: "pink", label: "💖 Pink" },
  { id: "monokai", label: "🍑 Monokai" },
  { id: "nord", label: "❄️ Nord" },
  { id: "dracula", label: "🧛 Dracula" },
  { id: "solarized", label: "☀️ Solarized" },
  { id: "gruvbox", label: "🎨 Gruvbox" },
  { id: "onedark", label: "🌑 One Dark" },
  { id: "github", label: "🐙 GitHub" },
  { id: "nord-frost", label: "❄️ Nord Frost" },
];

// ── Tab definitions
const TABS = [
  {
    id: "editor",
    label: "EDITOR",
    icon: (
      <svg
        width="13"
        height="13"
        viewBox="0 0 24 24"
        fill="none"
        stroke="currentColor"
        strokeWidth="2"
      >
        <polyline points="16 18 22 12 16 6" />
        <polyline points="8 6 2 12 8 18" />
      </svg>
    ),
  },
  {
    id: "tokens",
    label: "TOKENS",
    icon: (
      <svg
        width="13"
        height="13"
        viewBox="0 0 24 24"
        fill="none"
        stroke="currentColor"
        strokeWidth="2"
      >
        <circle cx="12" cy="12" r="3" />
        <path d="M12 1v4M12 19v4M4.22 4.22l2.83 2.83M16.95 16.95l2.83 2.83M1 12h4M19 12h4M4.22 19.78l2.83-2.83M16.95 7.05l2.83-2.83" />
      </svg>
    ),
  },
  {
    id: "ast",
    label: "AST",
    icon: (
      <svg
        width="13"
        height="13"
        viewBox="0 0 24 24"
        fill="none"
        stroke="currentColor"
        strokeWidth="2"
      >
        <circle cx="12" cy="4" r="2" />
        <circle cx="4" cy="20" r="2" />
        <circle cx="20" cy="20" r="2" />
        <line x1="12" y1="6" x2="4" y2="18" />
        <line x1="12" y1="6" x2="20" y2="18" />
      </svg>
    ),
  },
  {
    id: "output",
    label: "OUTPUT",
    icon: (
      <svg
        width="13"
        height="13"
        viewBox="0 0 24 24"
        fill="none"
        stroke="currentColor"
        strokeWidth="2"
      >
        <polyline points="4 17 10 11 4 5" />
        <line x1="12" y1="19" x2="20" y2="19" />
      </svg>
    ),
  },
];

export default function App() {
  const [activeTab, setActiveTab] = useState("tokens");
  const [code, setCode] = useState("");
  const [tokens, setTokens] = useState([]);
  const [ast, setAst] = useState(null);
  const [output, setOutput] = useState("");
  const [error, setError] = useState("");
  const [success, setSuccess] = useState(null); // null = never run
  const [loading, setLoading] = useState(false);
  const [status, setStatus] = useState("idle"); // idle | loading | ok | error
  const [siteTheme, setSiteTheme] = useState("dark");

  useEffect(() => {
    document.documentElement.setAttribute("data-theme", siteTheme);
  }, [siteTheme]);

  const [variables, setVariables] = useState({});

  const runCode = useCallback(async () => {
    if (!code.trim()) return;
    setLoading(true);
    setStatus("loading");
    try {
      const { data } = await axios.post("/compile", { code });
      setTokens(data.tokens ?? []);
      setAst(data.ast ?? null);
      setOutput(data.execution_output ?? "");
      setError(data.error ?? "");
      setSuccess(data.success);
      setStatus(data.success ? "ok" : "error");
      setVariables(data.variables ?? {});

      // Auto-switch to output tab if there's an error
      if (!data.success) {
        setActiveTab("output");
      }
    } catch (err) {
      const msg = err.response?.data?.detail ?? err.message ?? "Network error";
      setError(msg);
      setSuccess(false);
      setStatus("error");
    } finally {
      setLoading(false);
    }
  }, [code, activeTab]);

  const handleReset = () => {
    setCode("");
    setTokens([]);
    setAst(null);
    setOutput("");
    setError("");
    setSuccess(null);
    setStatus("idle");
    setActiveTab("editor");
  };

  return (
    <div className="app">
      {/* ── HEADER ── */}
      <header className="header">
        {/* Logo */}
        <div className="logo">
          <div className="logo-dot" />
          <span>AetherScript</span>
          <span className="logo-version">v1.1.0</span>
        </div>

        {/* Theme Selector */}
        <select
          value={siteTheme}
          onChange={(e) => {
            setSiteTheme(e.target.value);
            document.documentElement.setAttribute("data-theme", e.target.value);
          }}
          style={{
            marginLeft: "auto",
            marginRight: "8px",
            fontSize: "12px",
            padding: "4px 8px",
            borderRadius: "6px",
            border: "1px solid var(--border)",
            background: "var(--bg-secondary)",
            color: "var(--text-primary)",
            cursor: "pointer",
          }}
        >
          {SITE_THEMES.map((t) => (
            <option key={t.id} value={t.id}>
              {t.label}
            </option>
          ))}
        </select>

        {/* Reset */}
        <button className="btn-reset" onClick={handleReset} title="Reset all">
          <svg
            width="15"
            height="15"
            viewBox="0 0 24 24"
            fill="none"
            stroke="currentColor"
            strokeWidth="2"
          >
            <path d="M3 12a9 9 0 1 0 9-9 9.75 9.75 0 0 0-6.74 2.74L3 8" />
            <path d="M3 3v5h5" />
          </svg>
        </button>
      </header>

      {/* ── CONTENT ── */}
      <main className="main-container">
        {/* LEFT: Fixed Editor */}
        <section className="col-left">
          <EditorPanel
            code={code}
            onChange={setCode}
            onRun={runCode}
            loading={loading}
            status={status}
          />
        </section>

        {/* RIGHT: Tabbed Panels */}
        <section className="col-right">
          <nav
            className="header"
            style={{ height: "38px", borderBottom: "1px solid var(--border)" }}
          >
            <div className="nav-tabs">
              <button
                className={`nav-tab ${activeTab === "tokens" ? "active" : ""}`}
                onClick={() => setActiveTab("tokens")}
              >
                Tokens
              </button>
              <button
                className={`nav-tab ${activeTab === "ast" ? "active" : ""}`}
                onClick={() => setActiveTab("ast")}
              >
                AST
              </button>
              <button
                className={`nav-tab ${activeTab === "output" ? "active" : ""}`}
                onClick={() => setActiveTab("output")}
              >
                Output
              </button>
            </div>
          </nav>

          <div
            style={{
              flex: 1,
              overflow: "hidden",
              display: "flex",
              flexDirection: "column",
            }}
          >
            {activeTab === "tokens" && <TokenPanel tokens={tokens} />}
            {activeTab === "ast" && <ASTPanel ast={ast} />}
            {activeTab === "output" && (
              <OutputPanel
                output={output}
                error={error}
                ast={ast}
                success={success}
                variables={variables}
              />
            )}
          </div>
        </section>
      </main>

      {/* ── LOADING OVERLAY ── */}
      {loading && (
        <div className="loading-overlay">
          <div className="spinner" />
          <span>Compiling…</span>
        </div>
      )}
    </div>
  );
}
