%{
#include <stdio.h>
%}

%x p

id {spatii}[a-zA-Z_][a-zA-Z_0-9]*{spatii}
spatii [ \n\t\r]*
impar {spatii}[a-zA-Z_]([a-zA-Z_0-9][a-zA-Z_0-9])*{spatii}
argsext {impar},({impar},{impar})*,{impar}
argsint {impar}(,{impar})*

%%

class[ \n]?"{" {BEGIN p;}
<INITIAL>\n[ ]*"private function "{id}"("{argsint}")" {printf("%s\n", yytext);}
<p>"private function "{id}"("{argsext}")" {printf("%s\n", yytext);}
<p>"}" {BEGIN INITIAL;}
<INITIAL,p>.|\n ;

%%

int yywrap ()
{
	return 1;
}
int main (int argc, char** argv)
{
	if (argc > 0)
		yyin = fopen (argv[1], "r");
	//yyout = fopen ("out.txt", "w");
	yylex();
	return 0;
}
