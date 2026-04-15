#include "ast.h"
#include <stdio.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern ASTNode* root;
extern int line_num;
extern int suppress_tokens;

int main(int argc, char** argv) {
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }

    // --- Pass 1: Lex everything to populate token stream (even on error) ---
    suppress_tokens = 0;
    while(yylex() != 0);

    // --- Reset for Pass 2 ---
    if (yyin != stdin) {
        fseek(yyin, 0, SEEK_SET);
    }
    line_num = 1;
    suppress_tokens = 1; // Don't print tokens again

    if (yyparse() == 0) {
        if (root) {
            print_ast_json(root, 0);
            printf("\n");
            free_ast(root);
        }
    } else {
        return 1;
    }

    return 0;
}
