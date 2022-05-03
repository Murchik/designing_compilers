%option noyywrap yylineno

%{
 #include "y.tab.h"
 #include <stdio.h>
 int ch;
 extern void yyerror(char *);
 extern "C" {
    int yylex(void);
}
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
    yylval.str = yytext;
    return LITERA;
}

("_"|{letter})("_"|{letter}|{digit})* {
    ch += yyleng;
    yylval.str = yytext;
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
