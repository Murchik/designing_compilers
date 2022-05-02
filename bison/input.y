%{
 #include <stdio.h>
 extern FILE *yyin;
 extern int yylineno;
 extern int ch;
 extern char *yytext;
 void yyerror(char *);
%}

%token WHILE DONE ID LITERA
%right ASSIGN
%left CMP

%%
program: while {
    printf("\nprogram\n");
}
while: WHILE '('comparison')' statement DONE {
    printf("\nwhile\n");
}
statement: assignment';' {
    printf("\nstatement\n");
}
           | assignment';' statement {
    printf("\nstatement\n");
}
assignment: identifier ASSIGN identifier{
    printf("\nassignment\n");
}
            | identifier ASSIGN literal {
    printf("\nassignment\n");
}
comparison: identifier CMP identifier {
    printf("\ncomparison\n");
}
literal: LITERA {
    printf("\nliteral\n");
}
identifier: ID {
    printf("\nprimary expression\n");
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
    yyparse();
    return 0;
}
