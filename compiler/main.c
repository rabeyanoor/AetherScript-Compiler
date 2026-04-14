#include "ast.h"
#include <stdio.h>

extern int yyparse();
extern FILE* yyin;
extern ASTNode* root;

int main(int argc, char** argv) {
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }

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
