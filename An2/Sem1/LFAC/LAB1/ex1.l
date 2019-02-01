%{
#include <stdio.h>
%}
cifra [0-9]
nr {cifra}+
%%
\<{nr}\> {ECHO;}
ab+  {printf ("[%s]\n", yytext);}
.|\n ;  
%%
int main(int argc, char** argv){
FILE *g;
if(argc>0)
 yyin = fopen(argv[1],"r");

/*if(!(g = fopen("out.txt","w")))
    fprintf(stderr,"eroare creare fisier!");
else
 yyout=g; */

yylex();

}



