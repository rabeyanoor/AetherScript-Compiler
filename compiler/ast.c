#include "ast.h"

ASTNode* create_node(NodeType type, char* value, ASTNode* left, ASTNode* mid, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->left = left;
    node->mid = mid;
    node->right = right;
    node->next = NULL;
    return node;
}

void print_indent(int indent) {
    for (int i = 0; i < indent; i++) printf("  ");
}

void print_ast_json(ASTNode* node, int indent) {
    if (!node) {
        printf("null");
        return;
    }

    printf("{\n");
    print_indent(indent + 1);
    printf("\"type\": ");
    switch (node->type) {
        case NODE_PROGRAM: printf("\"Program\""); break;
        case NODE_VAR_DECL: printf("\"VarDecl\""); break;
        case NODE_ASSIGN: printf("\"Assignment\""); break;
        case NODE_IF: printf("\"IfStatement\""); break;
        case NODE_WHILE: printf("\"WhileStatement\""); break;
        case NODE_PRINT: printf("\"PrintStatement\""); break;
        case NODE_RETURN: printf("\"ReturnStatement\""); break;
        case NODE_BINARY_OP: printf("\"BinaryExpression\""); break;
        case NODE_IDENTIFIER: printf("\"Identifier\""); break;
        case NODE_NUMBER: printf("\"Literal\""); break;
        case NODE_BLOCK: printf("\"Block\""); break;
    }

    if (node->value) {
        printf(",\n");
        print_indent(indent + 1);
        printf("\"value\": \"%s\"", node->value);
    }

    if (node->left) {
        printf(",\n");
        print_indent(indent + 1);
        printf("\"left\": ");
        print_ast_json(node->left, indent + 1);
    }
    if (node->mid) {
        printf(",\n");
        print_indent(indent + 1);
        printf("\"mid\": ");
        print_ast_json(node->mid, indent + 1);
    }
    if (node->right) {
        printf(",\n");
        print_indent(indent + 1);
        printf("\"right\": ");
        print_ast_json(node->right, indent + 1);
    }
    if (node->next) {
        printf(",\n");
        print_indent(indent + 1);
        printf("\"next\": ");
        print_ast_json(node->next, indent + 1);
    }

    printf("\n");
    print_indent(indent);
    printf("}");
}

void free_ast(ASTNode* node) {
    if (!node) return;
    if (node->value) free(node->value);
    free_ast(node->left);
    free_ast(node->mid);
    free_ast(node->right);
    free_ast(node->next);
    free(node);
}
