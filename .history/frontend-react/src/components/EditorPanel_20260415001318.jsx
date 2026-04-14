import Editor from "@monaco-editor/react";
import { useState, useEffect } from "react";

const DEFAULT_CODE = "";

export default function EditorPanel({
  code,
  onChange,
  onRun,
  loading,
  status,
}) {
  const [editorTheme, setEditorTheme] = useState("aetherscript-dark");

  useEffect(() => {
    const updateTheme = () => {
      const siteTheme =
        document.documentElement.getAttribute("data-theme") || "dark";
      setEditorTheme(`aetherscript-${siteTheme}`);
    };
    updateTheme();
    const observer = new MutationObserver(updateTheme);
    observer.observe(document.documentElement, {
      attributes: true,
      attributeFilter: ["data-theme"],
    });
    return () => observer.disconnect();
  }, []);
  const handleEditorWillMount = (monaco) => {
    // Register a new language
    monaco.languages.register({ id: "aetherscript" });

    // Register a tokens provider for the language
    monaco.languages.setMonarchTokensProvider("aetherscript", {
      keywords: [
        "let",
        "if",
        "else",
        "while",
        "for",
        "print",
        "printf",
        "return",
        "fn",
        "true",
        "false",
        "type",
      ],
      operators: [
        "=",
        ">",
        "<",
        "!",
        "~",
        "?",
        ":",
        "==",
        "<=",
        ">=",
        "!=",
        "&&",
        "||",
        "++",
        "--",
        "+",
        "-",
        "*",
        "/",
        "&",
        "|",
        "^",
        "%",
        "<<",
        ">>",
        ">>>",
        "+=",
        "-=",
        "*=",
        "/=",
        "&=",
        "|=",
        "^=",
        "%=",
        "<<=",
        ">>=",
        ">>>=",
      ],
      symbols: /[=><!~?:&|+\-*\/\^%]+/,
      tokenizer: {
        root: [
          [
            /[a-z_$][\w$]*/,
            {
              cases: {
                "@keywords": "keyword",
                "@default": "identifier",
              },
            },
          ],
          { include: "@whitespace" },
          [/[{}()\[\]]/, "@brackets"],
          [/[<>](?!@symbols)/, "@brackets"],
          [
            /@symbols/,
            {
              cases: {
                "@operators": "operator",
                "@default": "",
              },
            },
          ],
          [/\d*\.\d+([eE][\-+]?\d+)?/, "number.float"],
          [/\d+/, "number"],
          [/[;,.]/, "delimiter"],
          [/"([^"\\]|\\.)*$/, "string.invalid"],
          [/"/, { token: "string.quote", bracket: "@open", next: "@string" }],
        ],
        string: [
          [/[^\\"]+/, "string"],
          [/\\./, "string.escape"],
          [/"/, { token: "string.quote", bracket: "@close", next: "@pop" }],
        ],
        whitespace: [
          [/[ \t\r\n]+/, "white"],
          [/\/\*/, "comment", "@comment"],
          [/\/\/.*$/, "comment"],
        ],
        comment: [
          [/[^\/*]+/, "comment"],
          [/\/\*/, "comment", "@push"],
          ["\\*/", "comment", "@pop"],
          [/[\/*]/, "comment"],
        ],
      },
    });

    // Define all themes
    monaco.editor.defineTheme("aetherscript-dark", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "e8a020", fontStyle: "bold" },
        { token: "identifier", foreground: "4ecdc4" },
        { token: "number", foreground: "e8a020" },
        { token: "string", foreground: "4ade80" },
        { token: "comment", foreground: "4a5568", fontStyle: "italic" },
        { token: "operator", foreground: "f87171" },
      ],
      colors: {
        "editor.background": "#1a1d27",
        "editorCursor.foreground": "#e8a020",
        "editor.lineHighlightBackground": "#1e2130",
        "editorLineNumber.foreground": "#4a5568",
        "editorLineNumber.activeForeground": "#8892b0",
      },
    });

    monaco.editor.defineTheme("aetherscript-light", {
      base: "vs",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "0066cc", fontStyle: "bold" },
        { token: "identifier", foreground: "333333" },
        { token: "number", foreground: "0066cc" },
        { token: "string", foreground: "008800" },
        { token: "comment", foreground: "999999", fontStyle: "italic" },
        { token: "operator", foreground: "cc0000" },
      ],
      colors: {
        "editor.background": "#ffffff",
        "editorCursor.foreground": "#0066cc",
        "editor.lineHighlightBackground": "#f0f4f8",
        "editorLineNumber.foreground": "#999999",
        "editorLineNumber.activeForeground": "#333333",
      },
    });

    monaco.editor.defineTheme("aetherscript-monokai", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "f92672", fontStyle: "bold" },
        { token: "identifier", foreground: "f8f8f2" },
        { token: "number", foreground: "ae81ff" },
        { token: "string", foreground: "e6db74" },
        { token: "comment", foreground: "75715e", fontStyle: "italic" },
        { token: "operator", foreground: "f92672" },
      ],
      colors: {
        "editor.background": "#272822",
        "editorCursor.foreground": "#f8f8f0",
        "editor.lineHighlightBackground": "#3e3d32",
        "editorLineNumber.foreground": "#75715e",
        "editorLineNumber.activeForeground": "#f8f8f0",
      },
    });

    monaco.editor.defineTheme("aetherscript-nord", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "81a1c1", fontStyle: "bold" },
        { token: "identifier", foreground: "d8dee9" },
        { token: "number", foreground: "a3be8c" },
        { token: "string", foreground: "a3be8c" },
        { token: "comment", foreground: "616e88", fontStyle: "italic" },
        { token: "operator", foreground: "81a1c1" },
      ],
      colors: {
        "editor.background": "#2e3440",
        "editorCursor.foreground": "#d8dee9",
        "editor.lineHighlightBackground": "#3b4252",
        "editorLineNumber.foreground": "#4c566a",
        "editorLineNumber.activeForeground": "#d8dee9",
      },
    });

    monaco.editor.defineTheme("aetherscript-pink", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "ff69b4", fontStyle: "bold" },
        { token: "identifier", foreground: "ffb6c1" },
        { token: "number", foreground: "ff1493" },
        { token: "string", foreground: "ff69b4" },
        { token: "comment", foreground: "db7093", fontStyle: "italic" },
        { token: "operator", foreground: "ff61d8" },
      ],
      colors: {
        "editor.background": "#1a0a1a",
        "editorCursor.foreground": "#ff69b4",
        "editor.lineHighlightBackground": "#2a1a2a",
        "editorLineNumber.foreground": "#8b4570",
        "editorLineNumber.activeForeground": "#ffb6c1",
      },
    });

    monaco.editor.defineTheme("aetherscript-dracula", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "ff79c6", fontStyle: "bold" },
        { token: "identifier", foreground: "f8f8f2" },
        { token: "number", foreground: "bd93f9" },
        { token: "string", foreground: "f1fa8c" },
        { token: "comment", foreground: "6272a4", fontStyle: "italic" },
        { token: "operator", foreground: "ff5555" },
      ],
      colors: {
        "editor.background": "#282a36",
        "editorCursor.foreground": "#f8f8f2",
        "editor.lineHighlightBackground": "#383a4a",
        "editorLineNumber.foreground": "#6272a4",
        "editorLineNumber.activeForeground": "#d0d0d0",
      },
    });

    monaco.editor.defineTheme("aetherscript-solarized", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "859900", fontStyle: "bold" },
        { token: "identifier", foreground: "839496" },
        { token: "number", foreground: "d33682" },
        { token: "string", foreground: "2aa198" },
        { token: "comment", foreground: "586e75", fontStyle: "italic" },
        { token: "operator", foreground: "cb4b16" },
      ],
      colors: {
        "editor.background": "#002b36",
        "editorCursor.foreground": "#839496",
        "editor.lineHighlightBackground": "#073642",
        "editorLineNumber.foreground": "#586e75",
        "editorLineNumber.activeForeground": "#93a1a1",
      },
    });

    monaco.editor.defineTheme("aetherscript-gruvbox", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "fb4933", fontStyle: "bold" },
        { token: "identifier", foreground: "ebdbb2" },
        { token: "number", foreground: "d3869b" },
        { token: "string", foreground: "b8bb26" },
        { token: "comment", foreground: "928374", fontStyle: "italic" },
        { token: "operator", foreground: "fe8019" },
      ],
      colors: {
        "editor.background": "#282828",
        "editorCursor.foreground": "#ebdbb2",
        "editor.lineHighlightBackground": "#3c3836",
        "editorLineNumber.foreground": "#665c54",
        "editorLineNumber.activeForeground": "#d5c4a1",
      },
    });

    monaco.editor.defineTheme("aetherscript-onedark", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "c678dd", fontStyle: "bold" },
        { token: "identifier", foreground: "abb2bf" },
        { token: "number", foreground: "d19a66" },
        { token: "string", foreground: "98c379" },
        { token: "comment", foreground: "5c6370", fontStyle: "italic" },
        { token: "operator", foreground: "61afef" },
      ],
      colors: {
        "editor.background": "#1e2127",
        "editorCursor.foreground": "#abb2bf",
        "editor.lineHighlightBackground": "#282c34",
        "editorLineNumber.foreground": "#4b5263",
        "editorLineNumber.activeForeground": "#9da5b4",
      },
    });

    monaco.editor.defineTheme("aetherscript-github", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "ff7b72", fontStyle: "bold" },
        { token: "identifier", foreground: "c9d1d9" },
        { token: "number", foreground: "a5d6ff" },
        { token: "string", foreground: "a5d6ff" },
        { token: "comment", foreground: "8b949e", fontStyle: "italic" },
        { token: "operator", foreground: "79c0ff" },
      ],
      colors: {
        "editor.background": "#0d1117",
        "editorCursor.foreground": "#c9d1d9",
        "editor.lineHighlightBackground": "#161b22",
        "editorLineNumber.foreground": "#484f58",
        "editorLineNumber.activeForeground": "#8b949e",
      },
    });

    monaco.editor.defineTheme("aetherscript-nord-frost", {
      base: "vs-dark",
      inherit: true,
      rules: [
        { token: "keyword", foreground: "81a1c1", fontStyle: "bold" },
        { token: "identifier", foreground: "eceff4" },
        { token: "number", foreground: "b48ead" },
        { token: "string", foreground: "a3be8c" },
        { token: "comment", foreground: "616e88", fontStyle: "italic" },
        { token: "operator", foreground: "88c0d0" },
      ],
      colors: {
        "editor.background": "#2e3440",
        "editorCursor.foreground": "#eceff4",
        "editor.lineHighlightBackground": "#3b4252",
        "editorLineNumber.foreground": "#4c566a",
        "editorLineNumber.activeForeground": "#d8dee9",
      },
    });
  };

  const handleKeyDown = (e) => {
    if ((e.ctrlKey || e.metaKey) && e.key === "Enter") {
      e.preventDefault();
      onRun();
    }
  };

  const dotClass =
    status === "ok"
      ? "ok"
      : status === "error"
        ? "err"
        : status === "loading"
          ? "loading"
          : "idle";
  const statusMsg =
    status === "ok"
      ? "Compilation successful"
      : status === "error"
        ? "Compilation failed"
        : status === "loading"
          ? "Compiling…"
          : "Ready — write code and press RUN";

  return (
    <div className="panel" onKeyDown={handleKeyDown}>
      <div className="panel-header">
        <span className="panel-title">Source Code</span>
        <span
          className="panel-count"
          style={{ fontSize: "11px", color: "var(--text-muted)" }}
        >
          Ctrl+Enter to run
        </span>
      </div>

      <div className="editor-wrapper">
        <Editor
          height="100%"
          language="aetherscript"
          value={code}
          onChange={(val) => onChange(val ?? "")}
          beforeMount={handleEditorWillMount}
          theme={editorTheme}
          options={{
            fontSize: 14,
            fontFamily: "'JetBrains Mono', 'Fira Code', monospace",
            fontLigatures: true,
            minimap: { enabled: false },
            lineNumbers: "on",
            scrollBeyondLastLine: false,
            automaticLayout: true,
            padding: { top: 16, bottom: 16 },
            scrollbar: { verticalScrollbarSize: 6, horizontalScrollbarSize: 6 },
            overviewRulerLanes: 0,
            renderLineHighlight: "all",
            cursorBlinking: "smooth",
            smoothScrolling: true,
            tabSize: 2,
            wordWrap: "off",
            contextmenu: false,
          }}
        />
      </div>

      <div className="run-bar">
        <button
          id="btn-run"
          className="btn-run"
          onClick={onRun}
          disabled={loading}
        >
          <span className="btn-run-icon">▶</span>
          RUN
        </button>
      </div>

      <div className="status-bar">
        <div className={`status-dot ${dotClass}`} />
        <span className="status-msg">{statusMsg}</span>
      </div>
    </div>
  );
}
