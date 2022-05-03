#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_TYPE_ID,
    NODE_TYPE_LITERAL,
    NODE_TYPE_OP,
    NODE_TYPE_WHILE,
    NODE_TYPE_STMT,
} NodeType;

typedef enum { OP_ASSIGN, OP_CMP } OpType;

typedef struct _Node {
    NodeType type;

    union {
        char* str;

        struct {
            OpType type;
            _Node *lhs, *rhs;
        } op;

        struct {
            _Node *cmp, *stmt;
        } loop;

        struct {
            _Node *assign, *next;
        } stmt;
    };
} Node;

void traverse(Node* n);

Node* make_id_node(const char* val);
Node* make_literal_node(const char* val);
Node* make_op_node(OpType op, Node* lhs, Node* rhs);
Node* make_while_node(Node* cmp, Node* stmt);
Node* make_stmt_node(Node* assign, Node* next);

#endif
