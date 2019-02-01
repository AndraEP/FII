/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_INCLUDE_PROJECT_YACC_H_INCLUDED
# define YY_YY_INCLUDE_PROJECT_YACC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIN = 258,
    TYPE = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    FOR = 263,
    PRINT = 264,
    PLSEQ = 265,
    MINEQ = 266,
    MULEQ = 267,
    DIVEQ = 268,
    INCR = 269,
    DECR = 270,
    AND = 271,
    OR = 272,
    EQEQ = 273,
    GTEQ = 274,
    LSEQ = 275,
    GT = 276,
    LS = 277,
    EQ = 278,
    AOPEN = 279,
    ACLOSE = 280,
    POPEN = 281,
    PCLOSE = 282,
    SEMICOLON = 283,
    COMMA = 284,
    PLS = 285,
    MIN = 286,
    MUL = 287,
    DIV = 288,
    STAR = 289,
    ID = 290,
    NUMBER = 291,
    CONSTANT = 292,
    CLASS = 293,
    CACCESS = 294,
    DOTS = 295,
    NOTEQ = 296,
    BOPEN = 297,
    BCLOSE = 298,
    NOT = 299
  };
#endif
/* Tokens.  */
#define MAIN 258
#define TYPE 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define FOR 263
#define PRINT 264
#define PLSEQ 265
#define MINEQ 266
#define MULEQ 267
#define DIVEQ 268
#define INCR 269
#define DECR 270
#define AND 271
#define OR 272
#define EQEQ 273
#define GTEQ 274
#define LSEQ 275
#define GT 276
#define LS 277
#define EQ 278
#define AOPEN 279
#define ACLOSE 280
#define POPEN 281
#define PCLOSE 282
#define SEMICOLON 283
#define COMMA 284
#define PLS 285
#define MIN 286
#define MUL 287
#define DIV 288
#define STAR 289
#define ID 290
#define NUMBER 291
#define CONSTANT 292
#define CLASS 293
#define CACCESS 294
#define DOTS 295
#define NOTEQ 296
#define BOPEN 297
#define BCLOSE 298
#define NOT 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 201 "src/project.y" /* yacc.c:1909  */

    int num;
    char* str;

#line 147 "include/project.yacc.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_PROJECT_YACC_H_INCLUDED  */
