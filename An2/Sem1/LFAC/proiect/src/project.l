%{

#include <stdio.h>
#include "project.yacc.h"

%}

%%

"main" {return MAIN;}
"const" {return CONST;}
"int"|"short"|"long"|"long long"|"long int"|"long long int"|"float"|"double"|"char" {yylval.str = strdup(yytext); return TYPE;}
"string" {return STRINGTYPE;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"Print" {return PRINT;}
"class" {return CLASS;}
"++" {yylval.str = strdup(yytext); return INCR;}
"--" {yylval.str = strdup(yytext); return DECR;}
"+=" {yylval.str = strdup(yytext); return PLSEQ;}
"-=" {yylval.str = strdup(yytext); return MINEQ;}
"*=" {yylval.str = strdup(yytext); return MULEQ;}
"/=" {yylval.str = strdup(yytext); return DIVEQ;}
"&&" {return AND;}
"||" {return OR;}
"==" {return EQEQ;}
"!=" {return NOTEQ;}
">=" {return GTEQ;}
"<=" {return LSEQ;}
">" {return GT;}
"<" {return LS;}
"!" {return NOT;}
"=" {return EQ;}
"{" {return AOPEN;}
"}" {return ACLOSE;}
"(" {return POPEN;}
")" {return PCLOSE;}
"[" {return BOPEN;}
"]" {return BCLOSE;}
";" {return SEMICOLON;}
"," {return COMMA;}
"+" {return PLS;}
"-" {return MIN;}
"*" {return MUL;}
"/" {return DIV;}
"." {return DOT;}
\"[_a-zA-Z0-9 ]*\" {yylval.str = strdup(yytext); return STRING;}
[_a-zA-Z][_a-zA-Z0-9]* {yylval.str = strdup(yytext); return ID;}
[0-9]+ {yylval.num = atoi(yytext); return NUMBER;}
[ \t] ;
\n {++yylineno;}
. {return yytext[0];}

%%

int yywrap() {return 1;}
