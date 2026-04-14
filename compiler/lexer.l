%{
#include "ast.h"
#include "parser.tab.h"
#include <string.h>

void store_token(const char* type, const char* value);
%}

%option noyywrap

DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
NUMBER      {DIGIT}+

%%

"let"           { store_token("KEYWORD", "let"); return LET; }
"if"            { store_token("KEYWORD", "if"); return IF; }
"else"          { store_token("KEYWORD", "else"); return ELSE; }
"while"         { store_token("KEYWORD", "while"); return WHILE; }
"print"         { store_token("KEYWORD", "print"); return PRINT; }
"return"        { store_token("KEYWORD", "return"); return RETURN; }
"fn"            { store_token("KEYWORD", "fn"); return FN; }

{ID}            { yylval.sval = strdup(yytext); store_token("IDENTIFIER", yytext); return IDENTIFIER; }
{NUMBER}        { yylval.sval = strdup(yytext); store_token("NUMBER", yytext); return NUMBER; }

"="             { store_token("OPERATOR", "="); return ASSIGN; }
"+"             { store_token("OPERATOR", "+"); return PLUS; }
"-"             { store_token("OPERATOR", "-"); return MINUS; }
"*"             { store_token("OPERATOR", "*"); return MULT; }
"/"             { store_token("OPERATOR", "/"); return DIV; }
"<"             { store_token("OPERATOR", "<"); return LT; }
">"             { store_token("OPERATOR", ">"); return GT; }
"=="            { store_token("OPERATOR", "=="); return EQ; }

"("             { store_token("SYMBOL", "("); return LPAREN; }
")"             { store_token("SYMBOL", ")"); return RPAREN; }
"{"             { store_token("SYMBOL", "{"); return LBRACE; }
"}"             { store_token("SYMBOL", "}"); return RBRACE; }
";"             { store_token("SYMBOL", ";"); return SEMICOLON; }
","             { store_token("SYMBOL", ","); return COMMA; }

[ \t\n]+        { /* skip whitespace */ }

.               { printf("Unknown character: %s\n", yytext); }

%%

// We will implement token storage in the main.c or here
void store_token(const char* type, const char* value) {
    // For now, we print to stderr so the backend can capture it separately
    // Or we store in a global list. Let's use stderr for quick bridge access.
    fprintf(stderr, "TOKEN:%s:%s\n", type, value);
}
