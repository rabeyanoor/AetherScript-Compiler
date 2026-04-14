#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_PROGRAM,
    NODE_VAR_DECL,
    NODE_ASSIGN,
    NODE_IF,
    NODE_WHILE,
    NODE_PRINT,
    NODE_RETURN,
    NODE_BINARY_OP,
    NODE_IDENTIFIER,
    NODE_NUMBER,
    NODE_BLOCK
} NodeType;

typedef struct ASTNode {
    NodeType type;
    char* value; // For identifiers and numbers
    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* mid; // For if-then-else
    struct ASTNode* next; // For linked lists of statements
} ASTNode;

ASTNode* create_node(NodeType type, char* value, ASTNode* left, ASTNode* mid, ASTNode* right);
void free_ast(ASTNode* node);
void print_ast_json(ASTNode* node, int indent);

#endif
