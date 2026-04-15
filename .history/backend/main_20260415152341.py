from fastapi import FastAPI, HTTPException
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
import subprocess
import os
import uuid
import json
import math

#  App Setup 
app = FastAPI(title="AetherScript Compiler API", version="1.1.0")

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# ── Absolute paths ────────────────────────────────────────────────────────────
BASE_DIR      = os.path.dirname(os.path.abspath(__file__))
PROJECT_DIR   = os.path.dirname(BASE_DIR)
COMPILER_PATH = os.path.join(PROJECT_DIR, "compiler", "aetherscript")
TEMP_DIR      = os.path.join(BASE_DIR, "temp_scripts")

os.makedirs(TEMP_DIR, exist_ok=True)

#  Request Model 
class CompileRequest(BaseModel):
    code: str

#  AST Interpreter ──────────────────────────────────────────────────────────
class ReturnSignal(Exception):
    def __init__(self, value):
        self.value = value

class BreakSignal(Exception):
    pass

class Interpreter:
    def __init__(self):
        self.variables = {}
        self.functions = {}
        self.output_buffer = []
        self.recursion_limit = 1000
        self.call_stack = 0
    
    def is_true(self, v):
        """Strict C-style truthiness helper"""
        return (v != 0 and v != "0" and v != "" and v is not None and v is not False)

    def evaluate(self, node):
        if node is None:
            return None

        node_type = node.get("type")

        # Handle linked list of statements (via next)
        # This is a generic handler to ensure we process linked statements
        # BUT we only want to do this if we're not already iterating in a block/program
        
        if node_type == "Program" or node_type == "Block":
            curr = node.get("left")
            last_res = None
            try:
                while curr:
                    last_res = self.evaluate(curr)
                    curr = curr.get("next")
            except ReturnSignal as rs:
                return rs.value
            return last_res

        elif node_type == "VarDecl":
            name = node.get("value")
            init_node = node.get("left")
            val = self.evaluate(init_node) if init_node else 0
            self.variables[name] = val
            return val

        elif node_type == "Assignment":
            name = node.get("value")
            val = self.evaluate(node.get("left"))
            self.variables[name] = val
            return val

        elif node_type == "Literal":
            val = node.get("value")
            if val is None: return 0
            if val == "true": return 1
            if val == "false": return 0
            try:
                if "." in val: return float(val)
                return int(val)
            except:
                return val

        elif node_type == "StringLiteral":
            val = node.get("value")
            if val:
                # Handle common escape sequences
                val = val.replace("\\n", "\n").replace("\\t", "\t").replace("\\r", "\r")
            return val

        elif node_type == "Identifier":
            name = node.get("value")
            return self.variables.get(name, 0)

        elif node_type == "BinaryExpression":
            op = node.get("value")
            # bool helper
            def bool_res(cond): return 1 if cond else 0

            left = self.evaluate(node.get("left"))
            right = self.evaluate(node.get("right"))

            if op == "+": return left + right
            if op == "-": return left - right
            if op == "*": return left * right
            if op == "/":
                if right == 0: raise Exception("Division by zero")
                # Use floor division for integers to match C behavior
                if isinstance(left, int) and isinstance(right, int):
                    return left // right
                return left / right
            if op == "%":
                if right == 0: raise Exception("Modulo by zero")
                return int(left) % int(right)
            if op == "<": return bool_res(left < right)
            if op == ">": return bool_res(left > right)
            if op == "<=": return bool_res(left <= right)
            if op == ">=": return bool_res(left >= right)
            if op == "==": return bool_res(left == right)
            if op == "!=": return bool_res(left != right)
            if op == "&&": return bool_res(self.is_true(left) and self.is_true(right))
            if op == "||": return bool_res(self.is_true(left) or self.is_true(right))
            return 0

        elif node_type == "UnaryExpression":
            op = node.get("value")
            operand = self.evaluate(node.get("left"))
            def bool_res(cond): return 1 if cond else 0
            
            if op == "-": return -float(operand) if operand is not None else 0
            if op == "!": return bool_res(not self.is_true(operand))
            return 0

        elif node_type == "IfStatement":
            cond = self.evaluate(node.get("left"))
            if self.is_true(cond):
                return self.evaluate(node.get("mid"))
            else:
                return self.evaluate(node.get("right"))

        elif node_type == "TernaryExpression":
            cond = self.evaluate(node.get("left"))
            if self.is_true(cond):
                return self.evaluate(node.get("mid"))
            else:
                return self.evaluate(node.get("right"))

        elif node_type == "WhileStatement":
            cond_node = node.get("left")
            body_node = node.get("mid")
            try:
                while self.is_true(self.evaluate(cond_node)):
                    self.evaluate(body_node)
            except BreakSignal:
                pass
            return None

        elif node_type == "ForStatement":
            self.evaluate(node.get("left")) # init
            cond_node = node.get("mid")
            tail_node = node.get("right")
            if tail_node:
                step_node = tail_node.get("left")
                body_node = tail_node.get("mid")
                try:
                    while self.is_true(self.evaluate(cond_node)):
                        self.evaluate(body_node)
                        self.evaluate(step_node)
                except BreakSignal:
                    pass
            return None

        elif node_type == "BreakStatement":
            raise BreakSignal()

        elif node_type == "PrintStatement":
            args_node = node.get("left")
            
            # Print arguments
            args_values = []
            curr_arg = args_node
            
            # Helper to evaluate arg list or single expression
            def collect_args(node):
                if not node: return []
                if node.get("type") == "ArgList":
                    return [self.evaluate(node.get("left"))] + collect_args(node.get("right"))
                return [self.evaluate(node)]

            args_values = collect_args(args_node)
            
            # Handle printf style formatting (simplified)
            if len(args_values) > 1 and isinstance(args_values[0], str) and "%" in args_values[0]:
                fmt = args_values[0]
                vals = args_values[1:]
                try:
                    # Simple replacement of %d, %f, %s
                    res = fmt
                    for v in vals:
                        # Find first occurrence of %d, %f, %s or %
                        import re
                        match = re.search(r"%[dfsu]", res)
                        if match:
                            res = res[:match.start()] + str(v) + res[match.end():]
                        else:
                            break
                    self.output_buffer.append(res)
                    return res
                except:
                    pass
            
            # Default print behavior
            res = " ".join(map(str, args_values))
            self.output_buffer.append(res)
            return args_values[0] if args_values else None

        elif node_type == "FuncDecl":
            name = node.get("value", "").strip()
            self.functions[name] = node
            return f"<fn {name}>"

        elif node_type == "CallExpression":
            self.call_stack += 1
            if self.call_stack > self.recursion_limit:
                raise Exception("Recursion limit exceeded")
            
            name = node.get("value", "").strip()
            args_node = node.get("left")
            
            # Evaluate arguments
            args_values = []
            curr_arg = args_node
            while curr_arg:
                if curr_arg.get("type") == "ArgList":
                    args_values.append(self.evaluate(curr_arg.get("left")))
                    curr_arg = curr_arg.get("right")
                else:
                    args_values.append(self.evaluate(curr_arg))
                    break

            if name == "sqrt" and args_values:
                self.call_stack -= 1
                return math.sqrt(float(args_values[0]))

            if name == "abs" and args_values:
                self.call_stack -= 1
                return abs(float(args_values[0]))

            if name == "round" and args_values:
                self.call_stack -= 1
                return round(float(args_values[0]))

            if name == "min" and len(args_values) >= 2:
                self.call_stack -= 1
                return min(float(args_values[0]), float(args_values[1]))

            if name == "max" and len(args_values) >= 2:
                self.call_stack -= 1
                return max(float(args_values[0]), float(args_values[1]))

            if name in ["print", "printf"] and args_values:
                # Basic printf implementation: replace %d, %f, %s with arguments
                if isinstance(args_values[0], str) and "%" in args_values[0] and len(args_values) > 1:
                    import re
                    fmt = args_values[0]
                    # This is a naive substitution for %d, %f, %s, etc.
                    placeholders = re.findall(r'%[dsf]', fmt)
                    if placeholders:
                        py_fmt = re.sub(r'%[dsf]', '{}', fmt)
                        try:
                            # Only use as many arguments as there are placeholders
                            count = len(placeholders)
                            formatted = py_fmt.format(*args_values[1:1+count])
                            self.output_buffer.append(formatted)
                            self.call_stack -= 1
                            return formatted
                        except Exception:
                            pass # Fallback to standard behavior if formatting fails

                # Default: append to output buffer
                val_to_print = args_values[-1]
                self.output_buffer.append(str(val_to_print))
                self.call_stack -= 1
                return val_to_print

            func_node = self.functions.get(name)
            if not func_node:
                self.call_stack -= 1
                return 0

            # Isolated Scoping for Function Call
            params_node = func_node.get("left")
            old_vars = self.variables.copy()
            
            curr_param = params_node
            idx = 0
            while curr_param and idx < len(args_values):
                self.variables[curr_param.get("value")] = args_values[idx]
                curr_param = curr_param.get("next")
                idx += 1
            
            try:
                result = self.evaluate(func_node.get("mid"))
            finally:
                if name != "main":
                    self.variables = old_vars
                self.call_stack -= 1
                
            return result

        elif node_type == "ReturnStatement":
            val = self.evaluate(node.get("left"))
            raise ReturnSignal(val)

        return None

    def run(self, ast):
        # Evaluate root node (Program) which recursively evaluates all statements
        res = self.evaluate(ast)

        # Auto-call main if defined
        if "main" in self.functions:
            res = self.evaluate({"type": "CallExpression", "value": "main", "left": None})
        
        # Return full output as string and variables
        return "".join(self.output_buffer), self.variables

# ── API Endpoints ─────────────────────────────────────────────────────────────
@app.get("/health")
async def health():
    compiler_ok = os.path.isfile(COMPILER_PATH) and os.access(COMPILER_PATH, os.X_OK)
    return {"status": "ok", "compiler_found": compiler_ok}

@app.post("/compile")
async def compile_code(request: CompileRequest):
    if not os.path.isfile(COMPILER_PATH):
        raise HTTPException(status_code=500, detail="Compiler binary missing.")

    file_id   = str(uuid.uuid4())
    temp_file = os.path.join(TEMP_DIR, f"temp_{file_id}.ml")

    try:
        with open(temp_file, "w") as f:
            f.write(request.code)

        result = subprocess.run(
            [COMPILER_PATH, temp_file],
            capture_output=True,
            text=True,
            timeout=5,
        )

        # Parse tokens from stderr
        tokens = []
        error_lines = []
        for line in result.stderr.splitlines():
            if line.startswith("TOKEN:"):
                parts = line.split(":", 2)
                if len(parts) == 3:
                    tokens.append({"type": parts[1], "value": parts[2]})
            elif line.strip():
                error_lines.append(line.strip())

        success = result.returncode == 0
        ast_data = None
        exec_output = ""
        variables = {}

        if success:
            try:
                ast_data = json.loads(result.stdout)
                # RUN INTERPRETER
                interpreter = Interpreter()
                final_output, final_vars = interpreter.run(ast_data)
                exec_output = final_output
                variables = final_vars
            except Exception as e:
                error_lines.append(f"Interpreter Error: {str(e)}")

        return {
            "success": success and not error_lines,
            "tokens":  tokens,
            "ast":     ast_data,
            "error":   "\n".join(error_lines) if error_lines else None,
            "execution_output": exec_output,
            "variables": variables
        }

    finally:
        if os.path.exists(temp_file):
            os.remove(temp_file)

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
