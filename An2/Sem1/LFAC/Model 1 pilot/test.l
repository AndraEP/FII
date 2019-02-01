%{
#include <stdio.h>
%}

%x p

nume [A-Za-z]{2,}
prenume [A-Za-z]{2,}
prenumemultiplu {prenume}([ -]{prenume})*
numecursa [A-Z]+:
nota ([1-9]|[1][0-5])
ocursa {numecursa}{nota}
lcursa \[{ocursa}(,{ocursa})*\]
%%
Pilot" "?\{ {BEGIN p;}
<p>nume:{nume}" "{prenumemultiplu} {printf("%s\n", yytext);}
<p>curse:{lcursa} {printf("%s\n", yytext);}
<p>\} {BEGIN INITIAL;}
<INITIAL,p>.|\n ;

%%
int yywrap()
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
