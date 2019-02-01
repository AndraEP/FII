%{
#include <stdio.h>
%}
%x unu
spatii [ \n\r\t]*
lidimpar {spatii}[a-zA-Z_]([a-zA-Z_0-9][a-zA-Z_0-9])*{spatii}
idstarimpar {lidimpar}(,{lidimpar},{lidimpar})*
lidpar {spatii}[a-zA-Z_]([a-zA-Z_0-9][a-zA-Z_0-9])*[a-zA-Z_0-9]{spatii}
idstarpar {lidpar}(,{lidpar})*
%%
class[ \n]?"{" {BEGIN unu;}
<unu>"public int "{idstarimpar} {printf("%s\n", yytext);}
<unu>("private"|"protected")" float "{idstarimpar} {printf("%s\n", yytext);}
<unu>"}" {BEGIN INITIAL;}
<INITIAL,unu>.|\n ;
%%
int yywrap ()
{
	return 1;
}
int main (int argc, char ** argv)
{
	if (argc > 0)
		yyin = fopen (argv[1], "r");
	//yyout = fopen ("out.txt", "w");
	yylex();
	return 0;
}
