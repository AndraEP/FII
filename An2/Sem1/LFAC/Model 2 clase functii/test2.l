%{
#include <stdio.h>
%}

%x p

id [a-zA-Z_][a-zA-Z_0-9]*
spatii [ \n\r\t]*
par {spatii}[a-zA-Z_]([a-zA-Z_0-9][a-zA-Z_0-9])*[a-zA-Z_0-9]{spatii}
impar {spatii}[a-zA-Z_]([a-zA-Z_0-9][a-zA-Z_0-9])*{spatii}
args ({par},)*{impar},({par},)*{impar},({par},)*{impar}(,{par})*


%%

class[ \n]?"{" {BEGIN p;}
<p>"private function "{id}" "*"("{args}")" {printf("%s\n", yytext);}
<p>"}" {BEGIN INITIAL;}
<INITIAL,p>.|\n ;

%%

int yywrap()
{
	return 1;
}

int main(int argc, char** argv)
{
	if (argc > 0)
		yyin = fopen (argv[1], "r");
	//yyout = fopen ("test2.out", "w");
	yylex();
	return 0;
}
