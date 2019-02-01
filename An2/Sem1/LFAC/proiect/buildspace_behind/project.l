%{

#include <stdio.h>
#include "project.tab.h"

int yylineno;

%}

%%

"main" {return MAIN;}
"int"|"float"|"char"|"string" {return BASETYPE;}
"if"|"while" {return CONTROL;}
"for" {return FOR;}
"Print" {return PRINT;}
"++" {return INCR;}
"--" {return DECR;}
"+=" {return PLSEQ;}
"-=" {return MINEQ;}
"*=" {return MULEQ;}
"/=" {return DIVEQ;}
"&&" {return AND;}
"||" {return OR;}
[_a-zA-Z][_a-zA-Z0-9]* {return ID;}
[0-9]+ {yylval = atoi(yytext); return NUMBER;}
[ \t] ;
\n {++yylineno;}
. {return yytext[0];}

%%

int yywrap() {return 1;}