#include "ast.h"

#include <string.h>

void print_tabs(int n) {
    for (int i = 0; i < n; ++i) {
        printf("\t");
    }
}

void _traverse(Node* n, int d) {
    switch (n->type) {
        case NODE_TYPE_ID:
            print_tabs(d);
            printf("id node: %s\n", n->str);
            break;

        case NODE_TYPE_LITERAL:
            print_tabs(d);
            printf("literal node: %s\n", n->str);
            break;

        case NODE_TYPE_OP:
            print_tabs(d);
            printf("op node %d:\n", n->op.type);

            _traverse(n->op.lhs, d + 1);
            _traverse(n->op.rhs, d + 1);
            break;

        case NODE_TYPE_WHILE:
            print_tabs(d);
            printf("loop node:\n");
            _traverse(n->loop.cmp, d + 1);

            print_tabs(d);
            printf("stmt:\n");
            _traverse(n->loop.stmt, d + 1);
            break;

        case NODE_TYPE_STMT:
            print_tabs(d);
            printf("stmt node:\n");

            print_tabs(d);
            printf("stmt assign:\n");
            _traverse(n->stmt.assign, d + 1);

            print_tabs(d);
            printf("stmt next:\n");
            Node* next = n->stmt.next;
            if (next != NULL) {
                _traverse(next, d);
            }
            break;
    }
}

void traverse(Node* n) {
    _traverse(n, 0);
}

char* copy_str(const char* src) {
    int len = strlen(src) + 1;
    char* s = (char*)malloc(sizeof(char) * len);
    s[len - 1] = '\0';
    strcpy(s, src);
    return s;
}

Node* make_node(NodeType type) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->type = type;
    return n;
}

Node* make_id_node(const char* val) {
    Node* n = make_node(NODE_TYPE_ID);
    n->str = copy_str(val);
    return n;
}

Node* make_literal_node(const char* val) {
    Node* n = make_node(NODE_TYPE_LITERAL);
    n->str = copy_str(val);
    return n;
}

Node* make_op_node(OpType op, Node* lhs, Node* rhs) {
    Node* n = make_node(NODE_TYPE_OP);
    n->op.type = op;
    n->op.lhs = lhs;
    n->op.rhs = rhs;
    return n;
}

Node* make_while_node(Node* cmp, Node* stmt) {
    Node* n = make_node(NODE_TYPE_WHILE);
    n->loop.cmp = cmp;
    n->loop.stmt = stmt;
    return n;
}

Node* make_stmt_node(Node* assign, Node* next) {
    Node* n = make_node(NODE_TYPE_STMT);
    n->stmt.assign = assign;
    n->stmt.next = next;
    return n;
}
