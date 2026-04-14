# AetherScript — Interactive Compiler Visualizer

A modern, interactive compiler and interpreter with **real-time token stream**, **AST visualization**, and **execution output**. Built with Flex, Bison, React, and FastAPI.

---

## What I Built

Over the past few days, I've been working on this project and finally completed it — **AetherScript**, a modern, interactive compiler and interpreter.

### 🔧 Components

- **Lexical Analyzer** — Built with Flex (Lex)
- **Parser** — Built with Bison (Yacc)
- **AST Interpreter** — Built with Python + FastAPI
- **Interactive Frontend** — Built with React + Vite + D3.js

### 🎯 Features

- **Real-time Token Stream** — See tokens as you type
- **AST Visualization** — Zoom, pan, and explore the Abstract Syntax Tree with D3.js
- **Variable State Inspector** — Watch variable states update during execution
- **C-style Syntax Support** — Variables, functions, loops, conditionals, printf, and more
- **Advanced Operators** — Ternary operator (`? :`), break statement, pre-increment (`++x`) all supported

### 💻 Tech Stack

| Layer       | Technology           |
| ----------- | -------------------- |
| Lexer       | Flex (Lex)           |
| Parser      | Bison (Yacc)         |
| Interpreter | Python + FastAPI     |
| Frontend    | React + Vite + D3.js |

---

## Project Structure

```
compilerX/
├── compiler/              # Flex & Bison compiler (C)
│   ├── lexer.l           # Lexical analyzer (Flex)
│   ├── parser.y          # Bison grammar
│   ├── ast.c / ast.h     # AST node definitions
│   ├── main.c            # Compiler driver
│   ├── Makefile          # Build configuration
│   └── aetherscript      # Compiled binary
├── backend/              # FastAPI interpreter server
│   ├── main.py           # AST interpreter & REST API
│   └── requirements.txt  # Python dependencies
├── frontend-react/       # React frontend
│   ├── src/
│   │   ├── components/
│   │   │   ├── ASTPanel.jsx      # D3.js tree visualization
│   │   │   ├── EditorPanel.jsx   # Code editor (Monaco)
│   │   │   ├── OutputPanel.jsx   # Execution output
│   │   │   └── TokenPanel.jsx    # Token stream display
│   │   └── App.jsx
│   └── package.json
├── local_bison/          # Bundled Bison binary
├── venv/                 # Python virtual environment
├── start_backend.sh      # Backend launcher script
└── README.md
```

---

## Quick Start

### One-Command Startup

```bash
# Start both backend and frontend
bash start_backend.sh    # Terminal 1: Backend on http://localhost:8000
cd frontend-react && npm run dev  # Terminal 2: Frontend on http://localhost:5173
```

Then open **http://localhost:5173** in your browser.

---

## Manual Setup

### Step 1: Build the Compiler

```bash
cd compiler
make clean && make
```

This creates the `aetherscript` binary using Flex and Bison.

### Step 2: Install Python Dependencies

```bash
pip install fastapi uvicorn
```

Or use the bundled virtual environment:

```bash
../venv/bin/python -m pip install fastapi uvicorn
```

### Step 3: Start Backend

```bash
cd ..
bash start_backend.sh
```

### Step 4: Start Frontend

```bash
cd frontend-react
npm install
npm run dev
```

---

## Supported Syntax

### Variables
```c
let x = 10;
int count = 0;
float pi = 3.14;
bool flag = true;
```

### Functions
```c
fn greet(name) {
    printf("Hello, %s!\n", name);
}
```

### Control Flow
```c
// If-Else
if (x > 10) {
    print(x);
} else {
    print(0);
}

// Ternary Operator
let result = (x > 0) ? x : -x;

// While Loop
while (i < 10) {
    print(i);
    i++;
}

// For Loop
for (int i = 0; i < 5; i++) {
    if (i == 3) break;
    print(i);
}
```

### Output
```c
// Simple print
print(x);

// C-style printf
printf("Value: %d\n", x);
printf("Name: %s, Age: %d\n", "Alice", 25);

// C++ style cout
cout << x << endl;
cout << "Hello, World!" << endl;
```

---

## What I Learned

Building this project helped me gain hands-on experience with:

- **Compiler Design** — Lexing, parsing, and AST generation
- **Parser Grammar** — Trial and error with Bison grammar rules
- **Full-Stack Development** — From C compiler to React frontend
- **REST API Integration** — Connecting compiler to web interface

---

## Future Enhancements

- [ ] Arrays and structs support
- [ ] Self-hosting compiler
- [ ] More built-in functions
- [ ] Error recovery in parser
- [ ] Step-by-step execution debugger

---

## License

MIT License — See LICENSE file for details.
