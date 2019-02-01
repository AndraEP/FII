%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FILE* yyin;
extern char* yytext;
int yylineno;


struct variable
{
    int value;
    char* name;
    char* type;
    _Bool value_present;
    _Bool is_const;
};
struct variable variables[256];
int k = 0; int kvechi = 0;

struct function
{
    char* type;
    char* name;
    char* args;
};
struct function functions[256];
int q = 0; int qvechi = 0;

int exp[256], n;

void Adaugare(int a)
{
    exp[n++] = a;
}

void Print()
{
    for (int i = 0; i < n; ++i)
    {
        printf ("Valoarea expresiei cu numarul %d este %d\n", i + 1, exp[i]);
    }
}

int already_declared(char* name)
{
    for (int i = 0; i < k; ++i)
    {
        if (strcmp(variables[i].name, name) == 0) return i;
    }
    return -1;
}

void declare_without_init(char* type, char* name, _Bool is_const)
{
    if (already_declared(name) != -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s is already declared", name);
        yyerror(buffer);
        exit(0);
    }
    if (is_const == 1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot declare const variable %s without initialization", name);
        yyerror(buffer);
        exit(0);
    }
    variables[k].type = strdup(type);
    variables[k].name = strdup(name);
    variables[k].value_present = 0;
    variables[k].is_const = 0;
    ++k;
}

void declare_with_init_value(char* type, char* name, int value, _Bool is_const)
{
    if (already_declared(name) != -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s is already declared", name);
        yyerror(buffer);
        exit(0);
    }
    variables[k].type = strdup(type);
    variables[k].name = strdup(name);
    variables[k].value = value;
    variables[k].value_present = 1;
    variables[k].is_const= is_const;
    ++k;
}

void declare_with_init_variable(char* type, char* name, char* variable, _Bool is_const)
{
    if (already_declared(name) != -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s is already declared", name);
        yyerror(buffer);
        exit(0);
    }
    int position = already_declared(variable);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s cannot be initialised with the undeclared variable %s", name, variable);
        yyerror(buffer);
        exit(0);
    }
    if (strcmp(type, variables[position].type) != 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s is not of the same type with variable %s", name, variables[position].name);
        yyerror(buffer);
        exit(0);
    }
    if (variables[position].value_present == 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s cannot be initialised with the uninitialised variable %s", name, variables[position].name);
        yyerror(buffer);
        exit(0);
    }
    variables[k].type = strdup(type);
    variables[k].name = strdup(name);
    variables[k].value = variables[position].value;
    variables[k].value_present = 1;
    variables[k].is_const = is_const;
    ++k;
}

int return_variable_value(char* name)
{
    int position = already_declared(name);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s was not declared", name);
        yyerror(buffer);
        exit(0);
    }
    if (variables[position].value_present == 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s does not have any value", name);
        yyerror(buffer);
        exit(0);
    }
    return variables[position].value;
}

void assign_value(char* name, int value)
{
    int position = already_declared(name);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s was not declared", name);
        yyerror(buffer);
        exit(0);
    }
    if (variables[position].is_const == 1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot assign value to const variable %s", name);
        yyerror(buffer);
        exit(0);
    }
    variables[position].value = value;
    variables[position].value_present = 1;
}

void increment_decrement(char* name, char* operator)
{
    int position = already_declared(name);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s was not declared", name);
        yyerror(buffer);
        exit(0);
    }
    if (variables[position].value_present == 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s does not have any value", name);
        yyerror(buffer);
        exit(0);
    }
    if (variables[position].is_const == 1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot assign value to const variable %s", name);
        yyerror(buffer);
        exit(0);
    }
    if (strcmp(operator, "++") == 0) variables[position].value++;
    if (strcmp(operator, "--") == 0) variables[position].value--;
}

void assign_number_with_operator(char* name, int value, char* operator)
{
    int position = already_declared(name);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s was not declared", name);
        yyerror(buffer);
        exit(0);
    }
    if (variables[position].value_present == 0)
    {
        char buffer[256];
        sprintf(buffer, "Variable %s does not have any value", name);
        yyerror(buffer);
        exit(0);
    }
    if (variables[position].is_const == 1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot assign value to const variable %s", name);
        yyerror(buffer);
        exit(0);
    }
    if (strcmp(operator, "+=") == 0) variables[position].value += value;
    if (strcmp(operator, "-=") == 0) variables[position].value -= value;
    if (strcmp(operator, "*=") == 0) variables[position].value *= value;
    if (strcmp(operator, "/=") == 0) variables[position].value /= value;
}

int function_already_declared(char* name, char* args)
{
    for (int i = 0; i < q; ++i)
    {
        if ((strcmp(functions[i].name, name) == 0) && (strcmp(functions[i].args, args) == 0)) return i;
    }
    return -1;
}

void declare_function (char* type, char* name, char* args)
{
    if (strlen(args) >= 2) args[strlen(args) - 2] = 0;
    if (function_already_declared(name, args) != -1)
    {
        char buffer[256];
        sprintf(buffer, "Cannot redeclare function %s with the same signature", name);
        yyerror(buffer);
        exit(0);
    }
    functions[q].type = type;
    functions[q].name = name;
    functions[q].args = args;
    ++q;
}

char* get_return_type (char* name, char* args)
{
    if (strlen(args) >= 2) args[strlen(args) - 2] = 0;
    int position = function_already_declared(name, args);
    if (position == -1)
    {
        char buffer[256];
        sprintf(buffer, "Function %s you are trying to call has not been declared", name);
        yyerror(buffer);
        exit(0);
    }
    char* type = malloc(256);
    strcpy(type, functions[position].type);
    return type;
}

void Enumerate(char* scope)
{
    FILE* f = fopen("symbol_table.txt", "a");
    fprintf(f, "In %s au fost declarate variabilele: ", scope);
    for (int i = kvechi; i < k; ++i) fprintf (f, "%s ", variables[i].name);
    kvechi = k;
    fprintf(f, "\n");
    fprintf(f, "In %s au fost declarate functiile: ", scope);
    for (int i = qvechi; i < q; ++i) fprintf (f, "%s ", functions[i].name);
    qvechi = q;
    fprintf (f, "\n\n");
    fclose(f);
}

%}

%token MAIN CONST TYPE IF STRINGTYPE ELSE WHILE FOR PRINT CLASS PLSEQ MINEQ MULEQ DIVEQ INCR DECR AND OR EQEQ NOTEQ GTEQ LSEQ GT LS NOT EQ AOPEN ACLOSE POPEN PCLOSE BOPEN BCLOSE SEMICOLON COMMA PLS MIN MUL DIV DOT STRING ID NUMBER
%start correct

%left COMMA
%left OR
%left AND
%left PLS MIN
%left MUL DIV
%left NOT
%left INCR DECR

%union
{
    int num;
    char* str;
}

%type <num> expr NUMBER
%type <str> TYPE ID INCR DECR PLSEQ MINEQ MULEQ DIVEQ parameters args function_call call_list STRING

%%

correct : program {printf("Program corect sintactic si semantic.\n"); Print();}
        ;


program : classes declarations main
        | declarations main
        | classes main
        | main
        ;

inceput_main : TYPE MAIN args {Enumerate("global");}
             ;

classes : class
        | classes class
        ;

class : CLASS ID AOPEN declarations ACLOSE SEMICOLON {Enumerate($2);}
      | CLASS ID AOPEN ACLOSE SEMICOLON {Enumerate($2);}

declarations : declaration
             | declarations declaration
             ;

declaration : CONST TYPE ID SEMICOLON {declare_without_init($2, $3, 1);}
            | TYPE ID SEMICOLON {declare_without_init($1, $2, 0);}
            | CONST TYPE ID EQ NUMBER SEMICOLON {declare_with_init_value($2, $3, $5, 1);}
            | TYPE ID EQ NUMBER SEMICOLON {declare_with_init_value($1, $2, $4, 0);}
            | CONST TYPE ID EQ ID SEMICOLON {declare_with_init_variable($2, $3, $5, 1);}
            | TYPE ID EQ ID SEMICOLON {declare_with_init_variable($1, $2, $4, 0);}
            | TYPE ID dimensions SEMICOLON
            | TYPE ID args {declare_function($1, $2, $3);}
            | STRINGTYPE ID SEMICOLON
            | STRINGTYPE ID EQ STRING SEMICOLON
            ;

dimensions : BOPEN NUMBER BCLOSE
           | dimensions BOPEN NUMBER BCLOSE

main : inceput_main AOPEN blocks ACLOSE {Enumerate("main");}
     ;

args : POPEN PCLOSE {$$ = malloc(256); $$[0] = 0;}
     | POPEN parameters PCLOSE {$$ = $2;}
     ;

parameters : TYPE ID {$$ = $1; strcat($$, ", ");}
           | parameters COMMA parameters {$$ = $1; strcat($$, $3);}
           ;

blocks : block
       | AOPEN block ACLOSE
       | blocks block
       ;

block : IF POPEN condition PCLOSE statement SEMICOLON
      | IF POPEN condition PCLOSE statement SEMICOLON ELSE statement SEMICOLON
      | IF POPEN condition PCLOSE statement SEMICOLON ELSE AOPEN statements ACLOSE
      | IF POPEN condition PCLOSE AOPEN statements ACLOSE
      | IF POPEN condition PCLOSE AOPEN statements ACLOSE ELSE statement SEMICOLON
      | IF POPEN condition PCLOSE AOPEN statements ACLOSE ELSE AOPEN statements ACLOSE
      | FOR POPEN statement SEMICOLON condition SEMICOLON statement PCLOSE statement SEMICOLON
      | FOR POPEN statement SEMICOLON condition SEMICOLON statement PCLOSE AOPEN statements ACLOSE
      | WHILE POPEN condition PCLOSE statement SEMICOLON
      | WHILE POPEN condition PCLOSE AOPEN statements ACLOSE
      | statement SEMICOLON
      | declaration
      ;

condition : operand
          | operand LS operand
          | operand GT operand
          | operand LSEQ operand
          | operand GTEQ operand
          | operand EQEQ operand
          | operand NOTEQ operand
          | NOT operand
          | condition AND condition
          | condition OR condition
          | POPEN condition PCLOSE
          ;

operand : ID
        | NUMBER
        | function_call
        ;

statements : statement SEMICOLON
           | statements statement SEMICOLON
           ;

statement : ID EQ expr {assign_value($1, $3);}
          | ID INCR {increment_decrement($1, $2);}
          | ID DECR {increment_decrement($1, $2);}
          | INCR ID {increment_decrement($2, $1);}
          | DECR ID {increment_decrement($2, $1);}
          | ID PLSEQ expr {assign_number_with_operator($1, $3, $2);}
          | ID MINEQ expr {assign_number_with_operator($1, $3, $2);}
          | ID MULEQ expr {assign_number_with_operator($1, $3, $2);}
          | ID DIVEQ expr {assign_number_with_operator($1, $3, $2);}
          | function_call
          | PRINT POPEN expr PCLOSE {Adaugare($3);}
          | statement COMMA statement
          | 
          ;

expr : expr PLS expr {$$ = $1 + $3;}
     | expr MIN expr {$$ = $1 - $3;}
     | expr MUL expr {$$ = $1 * $3;}
     | expr DIV expr {$$ = $1 / $3;}
     | POPEN expr PCLOSE {$$ = $2;}
     | NUMBER {$$ = $1;}
     | ID BOPEN NUMBER BCLOSE {$$ = 0;}
     | ID DOT ID {$$ = 0;}
     | ID {$$ = return_variable_value($1);}
     ;

function_call : ID POPEN call_list PCLOSE {$$ = get_return_type ($1, $3);}
              ;

call_list : expr {$$ = malloc (256); strcpy($$, "int, ");}
          | function_call {$$ = $1; strcat($$, ", ");}
          | call_list COMMA call_list {$$ = $1; strcat($$, $3);}
          ;

%%

int yyerror(char * s)
{
    printf("error: %s\n line: %d\n", s, yylineno);
}

int main(int argc, char** argv)
{
    if (argc > 1) yyin = fopen(argv[1], "r");
    FILE* f = fopen("symbol_table.txt", "w");
    fclose(f);
    yyparse();
    f = fopen("symbol_table.txt", "a");
    fprintf(f, "Functiile declarate sunt:\n");
    for (int i = 0; i < q; ++i)
    {
        fprintf(f, "[%s] %s (%s)\n", functions[i].type, functions[i].name, functions[i].args);
    }
    fclose(f);
} 
