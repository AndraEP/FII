%{

#include <stdio.h>

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}

%token MAIN BASETYPE CONTROL FOR PRINT PLSEQ MINEQ MULEQ DIVEQ INCR DECR AND OR ID NUMBER
%start program

%left ','
%left '+' '-'
%left '*' '/'
%left INCR DECR
%left OR
%left AND

%%

program : declarations main {printf("Program corect sintactic.\n");}
        ;

declarations :  declaration
	     |  declarations declaration
             ;

declaration : type ids ';'
            ;

type : BASETYPE
     | type '*'
     ;

ids : ID
    | ids ',' ID
    ;

main : BASETYPE MAIN args '{' blocks '}'
     ;

args : '(' ')'
     | '(' parameters ')'
     ;

parameters : type ID
           | parameters ',' parameters
           ;

blocks : block
       | blocks block
       ;

block : CONTROL '(' condition ')' statement ';'
      | CONTROL '(' condition ')' '{' statements '}'
      | FOR '(' statement ';' condition ';' statement ')' statement ';'
      | FOR '(' statement ';' condition ';' statement ')' '{' statements '}'
      | statement ';'
      ;

condition : ID '<' NUMBER
          | ID '<' ID
          | ID '>' NUMBER
          | ID '>' ID
          | ID '<' '=' NUMBER
          | ID '<' '=' ID
          | ID '>' '=' NUMBER
          | ID '>' '=' ID
          | ID '=' '=' NUMBER
          | ID '=' '=' ID
          | '(' condition ')'
          | condition AND condition
          | condition OR condition
          ;

statements : statement ';'
           | statements statement ';'
           ;

statement : ID '=' ID
          | ID '=' NUMBER
          | ID '(' call_list ')'
          | ID INCR
          | ID DECR
          | INCR ID
          | DECR ID
          | ID '+' '=' ID
          | ID '+' '=' NUMBER
          | ID '-' '=' ID
          | ID '-' '=' NUMBER
          | ID '*' '=' ID
          | ID '*' '=' NUMBER
          | ID '/' '=' ID
          | ID '/' '=' NUMBER
          | expreq
          | PRINT '(' expr ')' {printf ("Valoarea expresiei: %d\n", $3);}
          | statement ',' statement
          ;

expreq : expr PLSEQ expr {$1 = $1 + $3;}
       | expr MINEQ expr {$1 = $1 - $3;}
       | expr MULEQ expr {$1 = $1 * $3;}
       | expr DIVEQ expr {$1 = $1 / $3;}
       | expr INCR {$$ = $1 + 1;}
       | expr DECR {$$ = $1 - 1;}

expr : expr '+' expr {$$ = $1 + $3;}
     | expr '-' expr {$$ = $1 - $3;}
     | expr '*' expr {$$ = $1 * $3;}
     | expr '/' expr {$$ = $1 / $3;}
     | '(' expr ')' {$$ = $2;}
     | NUMBER {$$ = $1;}
     ;

call_list : NUMBER
          | call_list ',' NUMBER
          ;

%%

int yyerror(char * s)
{
    printf("error: %s\n line: %d\n", s, yylineno);
}

int main(int argc, char** argv)
{
    if (argc > 1) yyin = fopen(argv[1], "r");
    yyparse();
} 