/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_XFORM = 258,
     T_COND = 259,
     T_EXISTS = 260,
     T_NUM = 261,
     T_REPEAT = 262,
     T_UNIQUE = 263,
     T_ENUM = 264,
     T_PICK = 265,
     T_RESOURCE = 266,
     T_LITERAL = 267,
     T_IDENT = 268,
     T_INTEGER = 269,
     T_DEREF = 270,
     T_ELLIPSIS = 271
   };
#endif
/* Tokens.  */
#define T_XFORM 258
#define T_COND 259
#define T_EXISTS 260
#define T_NUM 261
#define T_REPEAT 262
#define T_UNIQUE 263
#define T_ENUM 264
#define T_PICK 265
#define T_RESOURCE 266
#define T_LITERAL 267
#define T_IDENT 268
#define T_INTEGER 269
#define T_DEREF 270
#define T_ELLIPSIS 271




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 43 "parser.y"

  double f;
  int i;
  char *s;
  pNode n;
  pOption o;
  pRule r;
  pParam p; /* superceded; pListNode is a generic list of pointer-sized 
	       scalar quantities */
  pListNode l;
  pMapAction ma;
  pMapOpt mo;
  int *pi;
  pTransCmd tc;
  pTransOpt to;
  pTransformation tr;
  pInstr c;



/* Line 2068 of yacc.c  */
#line 103 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


