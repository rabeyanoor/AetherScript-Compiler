from fastapi import FastAPI, HTTPException
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
import subprocess
import os
import uuid
import json
import tempfile

# ── App Setup ────────────────────────────────────────────────────────────────
app = FastAPI(title="AetherScript Compiler API", version="1.0.0")

# Allow all origins so the frontend (any port) can talk to us
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# ── Absolute paths (reliable regardless of where we are run from) ─────────────
BASE_DIR      = os.path.dirname(os.path.abspath(__file__))          # .../backend
PROJECT_DIR   = os.path.dirname(BASE_DIR)                           # .../compilerX--1
COMPILER_PATH = os.path.join(PROJECT_DIR, "compiler", "minilang")   # .../compiler/minilang
TEMP_DIR      = os.path.join(BASE_DIR, "temp_scripts")              # .../backend/temp_scripts

os.makedirs(TEMP_DIR, exist_ok=True)

# ── Request Model ─────────────────────────────────────────────────────────────
class CompileRequest(BaseModel):
    code: str

# ── Health Check ──────────────────────────────────────────────────────────────
@app.get("/")
async def root():
    compiler_ok = os.path.isfile(COMPILER_PATH) and os.access(COMPILER_PATH, os.X_OK)
    return {
        "status": "running",
        "compiler": COMPILER_PATH,
        "compiler_found": compiler_ok,
    }

@app.get("/health")
async def health():
    compiler_ok = os.path.isfile(COMPILER_PATH) and os.access(COMPILER_PATH, os.X_OK)
    if not compiler_ok:
        raise HTTPException(
            status_code=500,
            detail=f"Compiler not found or not executable at: {COMPILER_PATH}"
        )
    return {"status": "ok", "compiler": COMPILER_PATH}

# ── Compile Endpoint ──────────────────────────────────────────────────────────
@app.post("/compile")
async def compile_code(request: CompileRequest):
    # ── Validate compiler exists ───────────────────────────────────────────
    if not os.path.isfile(COMPILER_PATH):
        raise HTTPException(
            status_code=500,
            detail=f"Compiler binary not found at: {COMPILER_PATH}. "
                   f"Run 'make' inside the compiler/ directory first."
        )
    if not os.access(COMPILER_PATH, os.X_OK):
        raise HTTPException(
            status_code=500,
            detail=f"Compiler binary is not executable. Run: chmod +x {COMPILER_PATH}"
        )

    # ── Write code to a temp file ──────────────────────────────────────────
    file_id   = str(uuid.uuid4())
    temp_file = os.path.join(TEMP_DIR, f"temp_{file_id}.ml")

    try:
        with open(temp_file, "w") as f:
            f.write(request.code)

        # ── Run the compiler (5-second timeout) ───────────────────────────
        result = subprocess.run(
            [COMPILER_PATH, temp_file],
            capture_output=True,
            text=True,
            timeout=5,
        )

        # ── Parse tokens from stderr ───────────────────────────────────────
        tokens = []
        error_lines = []
        for line in result.stderr.splitlines():
            line = line.strip()
            if line.startswith("TOKEN:"):
                parts = line.split(":", 2)
                if len(parts) == 3:
                    tokens.append({"type": parts[1], "value": parts[2]})
            elif line:          # real error messages
                error_lines.append(line)

        # ── Parse AST JSON from stdout ─────────────────────────────────────
        raw_ast  = result.stdout.strip()
        ast_data = None
        if raw_ast:
            try:
                ast_data = json.loads(raw_ast)
            except json.JSONDecodeError:
                # Return raw string so frontend can still show something
                ast_data = {"raw": raw_ast}

        success = result.returncode == 0

        return {
            "success": success,
            "tokens":  tokens,
            "ast":     ast_data,
            "error":   "\n".join(error_lines) if error_lines else None,
            "raw_output": raw_ast if not success else None,
        }

    except subprocess.TimeoutExpired:
        raise HTTPException(status_code=408, detail="Compiler timed out after 5 seconds.")
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
    finally:
        if os.path.exists(temp_file):
            os.remove(temp_file)

# ── Entry Point ───────────────────────────────────────────────────────────────
if __name__ == "__main__":
    import uvicorn
    print(f"[AetherScript Backend]")
    print(f"  Compiler : {COMPILER_PATH}")
    print(f"  Temp dir : {TEMP_DIR}")
    print(f"  Compiler exists: {os.path.isfile(COMPILER_PATH)}")
    uvicorn.run(app, host="0.0.0.0", port=8000, reload=False)
