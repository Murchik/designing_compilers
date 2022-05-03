%{
 #include <stdio.h>
 extern FILE *yyin;
 extern int yylineno;
 extern int ch;
 extern char *yytext;

 void yyerror(char *);
 extern "C" {
    int yylex(void);
}

 #include "ast.h"

 Node* root;
%}

%code requires {
    #include "ast.h"
}

%union {
    Node* node;
    char* str;
}

%type<node> program
%type<node> while
%type<node> statement
%type<node> assignment
%type<node> comparison
%type<node> identifier
%type<node> literal

%token<str> ID
%token<str> LITERA

%token WHILE DONE
%right ASSIGN
%left CMP

%%
program: while {
    root = $1;
}
statement: assignment';' {
    $$ = make_stmt_node($1, NULL);
}
           | assignment';' statement {
    $$ = make_stmt_node($1, $3);
}
while: WHILE '('comparison')' statement DONE {
    $$ = make_while_node($3, $5);
}
assignment: identifier ASSIGN identifier{
    $$ = make_op_node(OP_ASSIGN, $1, $3);
}
            | identifier ASSIGN literal {
    $$ = make_op_node(OP_ASSIGN, $1, $3);
}
comparison: identifier CMP identifier {
    $$ = make_op_node(OP_CMP, $1, $3);
}
literal: LITERA {
    $$ = make_literal_node($1);
}
identifier: ID {
    $$ = make_id_node($1);
}
%%

void yyerror(char *errmsg) {
    fprintf(stderr, "%s (%d, %d): %s\n", errmsg, yylineno, ch, yytext);
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("\nNot enough arguments. Please specify filename. \n");
        return -1;
    }
    if((yyin = fopen(argv[1], "r")) == NULL) {
        printf("\nCannot open file %s.\n", argv[1]);
        return -1;
    }
    ch = 1;
    yylineno = 1;

    int ret = yyparse();
    if (ret == 0) {
        traverse(root);
    }

    return 0;
}
