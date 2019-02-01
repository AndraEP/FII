%{
#include <stdio.h>
%}

%x p

spatii [ \n\r\t]*
id {spatii}[a-zA-Z_][a-zA-Z_0-9]*{spatii}
idimpar {spatii}[a-zA-Z_]([a-zA-Z_0-9][a-zA-Z_0-9])*{spatii}
l3k2idimpar {idimpar},{idimpar}(,{idimpar},{idimpar},{idimpar})*
lid {id}(,{id})*

%%

class[ \n]?"{" {BEGIN p;}
<INITIAL>"public int "{l3k2idimpar} {printf("%s\n", yytext);}
<p>("private"|"protected")" int "{lid} {printf("%s\n", yytext);}
<p>"}" {BEGIN INITIAL;}
<INITIAL,p>.|\n ;

%%

int yywrap() {return 1;}

int main(int argc, char** argv)
{
    if(argc > 0) yyin = fopen(argv[1], "r");
    //yyout = fopen("out.txt", "w");
    yylex();
}
