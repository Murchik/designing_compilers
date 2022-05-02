%option noyywrap yylineno

%{
 #include "y.tab.h"
 #include <stdio.h>
 int ch;
 extern int yylex(void);
 extern void yyerror(char *);
%}

digit[0-9]
letter[a-zA-Z]
delim[();]
oper[<>=]
ws[ \t\n]

%%
while {
    ch += yyleng;
    return WHILE;
}

done {
    ch += yyleng;
    return DONE;
}

{delim} {
    ch += yyleng;
    return *yytext;
}

{oper} {
    ch += yyleng;
    return CMP;
}

(\".*\") {
    ch += yyleng;
    return LITERA;
}

("_"|{letter})("_"|{letter}|{digit})* {
    ch += yyleng;
    return ID;
}

":=" {
    ch += yyleng;
    return ASSIGN;
}

{ws}+ {
    ch += yyleng;
}

. {
    yyerror("Unknown character");
    ch += yyleng;
}
%%
