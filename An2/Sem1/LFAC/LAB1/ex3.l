%{
#include <stdio.h>
%}
%x pas
%%
password: {ECHO; BEGIN pas;}
<pas>[^ \n] {printf("*");}
<pas>[ \n] {ECHO; BEGIN 0;} 
[0-9]+ {printf("[%s]", yytext);}
%%
int main(int argc, char** argv){
if(argc>0)
 yyin = fopen(argv[1],"r");
yylex();
}
