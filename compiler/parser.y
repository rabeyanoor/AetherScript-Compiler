%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);

ASTNode* root;
%}

%union {
    char* sval;
    struct ASTNode* nval;
}

%token <sval> IDENTIFIER NUMBER
%token LET IF ELSE WHILE PRINT RETURN FN
%token ASSIGN PLUS MINUS MULT DIV LT GT EQ
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA

%type <nval> program statement_list statement var_decl assignment if_stmt while_stmt print_stmt expression term factor block

%start program

%%

program:
    statement_list { root = create_node(NODE_PROGRAM, NULL, $1, NULL, NULL); }
    ;

statement_list:
    statement { $$ = $1; }
    | statement statement_list { $1->next = $2; $$ = $1; }
    ;

statement:
    var_decl { $$ = $1; }
    | assignment { $$ = $1; }
    | if_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | print_stmt { $$ = $1; }
    | block { $$ = $1; }
    ;

var_decl:
    LET IDENTIFIER ASSIGN expression SEMICOLON {
        $$ = create_node(NODE_VAR_DECL, $2, $4, NULL, NULL);
    }
    ;

assignment:
    IDENTIFIER ASSIGN expression SEMICOLON {
        $$ = create_node(NODE_ASSIGN, $1, $3, NULL, NULL);
    }
    ;

if_stmt:
    IF LPAREN expression RPAREN block {
        $$ = create_node(NODE_IF, NULL, $3, $5, NULL);
    }
    | IF LPAREN expression RPAREN block ELSE block {
        $$ = create_node(NODE_IF, NULL, $3, $5, $7);
    }
    ;

while_stmt:
    WHILE LPAREN expression RPAREN block {
        $$ = create_node(NODE_WHILE, NULL, $3, $5, NULL);
    }
    ;

print_stmt:
    PRINT LPAREN expression RPAREN SEMICOLON {
        $$ = create_node(NODE_PRINT, NULL, $3, NULL, NULL);
    }
    ;

block:
    LBRACE statement_list RBRACE {
        $$ = create_node(NODE_BLOCK, NULL, $2, NULL, NULL);
    }
    ;

expression:
    term { $$ = $1; }
    | expression PLUS term { $$ = create_node(NODE_BINARY_OP, "+", $1, NULL, $3); }
    | expression MINUS term { $$ = create_node(NODE_BINARY_OP, "-", $1, NULL, $3); }
    | expression LT term { $$ = create_node(NODE_BINARY_OP, "<", $1, NULL, $3); }
    | expression GT term { $$ = create_node(NODE_BINARY_OP, ">", $1, NULL, $3); }
    | expression EQ term { $$ = create_node(NODE_BINARY_OP, "==", $1, NULL, $3); }
    ;

term:
    factor { $$ = $1; }
    | term MULT factor { $$ = create_node(NODE_BINARY_OP, "*", $1, NULL, $3); }
    | term DIV factor { $$ = create_node(NODE_BINARY_OP, "/", $1, NULL, $3); }
    ;

factor:
    NUMBER { $$ = create_node(NODE_NUMBER, $1, NULL, NULL, NULL); }
    | IDENTIFIER { $$ = create_node(NODE_IDENTIFIER, $1, NULL, NULL, NULL); }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}
