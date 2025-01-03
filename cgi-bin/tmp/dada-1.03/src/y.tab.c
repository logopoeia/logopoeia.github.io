/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 15 "parser.y"


#include <time.h>
#include <stdlib.h> /* NULL */
#include <stdio.h>
#include "rtn.h"
#include "check.h"
#include "map.h"
#include "transform.h"
#include "machine.h"
#include "ptrlist.h"

#define YYERROR_VERBOSE 1
#define YYDEBUG 1

pRule initial_rule=NULL;

#ifndef YYBISON
int yydebug=0;
#endif

pListNode transformations = NULL;
extern int verbose;

extern void use_rtn(pRule rtn);



/* Line 268 of yacc.c  */
#line 100 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
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



/* Line 293 of yacc.c  */
#line 189 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 201 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   271

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    35,    25,     2,     2,
      28,    29,    23,    22,    30,    21,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,    27,
       2,    34,    17,    15,     2,     2,     2,     2,     2,     2,
       2,    20,     2,     2,     2,     2,     2,    31,     2,     2,
       2,     2,    32,     2,     2,     2,    19,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,    33,    37,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      16,    18
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    12,    15,    20,    26,
      34,    40,    43,    45,    49,    54,    56,    60,    61,    64,
      65,    70,    73,    75,    79,    83,    85,    89,    92,    94,
      98,   100,   102,   105,   107,   109,   113,   116,   120,   124,
     127,   131,   134,   137,   140,   144,   151,   158,   161,   164,
     171,   173,   175,   180,   181,   183,   187,   191,   194,   196,
     198,   200,   203,   207,   211,   215,   219,   223,   227,   231,
     235
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    -1,    42,    43,    -1,    42,
      50,    -1,    42,    44,    -1,    13,    26,    55,    27,    -1,
      11,    13,    26,    55,    27,    -1,    13,    28,    54,    29,
      26,    55,    27,    -1,     3,    13,    26,    45,    27,    -1,
      46,    45,    -1,    46,    -1,    12,    26,    47,    -1,    48,
      13,    49,    27,    -1,    14,    -1,    14,    30,    14,    -1,
      -1,    12,    49,    -1,    -1,    13,    26,    51,    27,    -1,
      51,    52,    -1,    52,    -1,    12,    31,    53,    -1,    12,
      32,    12,    -1,    12,    -1,    12,    24,    12,    -1,    54,
      13,    -1,    13,    -1,    56,    33,    55,    -1,    56,    -1,
      57,    -1,    57,    58,    -1,    58,    -1,    59,    -1,    58,
      17,    13,    -1,    16,    58,    -1,    13,    19,    58,    -1,
      13,    34,    58,    -1,    35,    13,    -1,    36,    60,    37,
      -1,    15,    58,    -1,    58,    23,    -1,    58,    22,    -1,
      38,    55,    39,    -1,     7,    28,    58,    30,    14,    29,
      -1,     7,    28,    58,    30,    13,    29,    -1,     8,    58,
      -1,     9,    58,    -1,    10,    28,    14,    30,    58,    29,
      -1,    12,    -1,    13,    -1,    13,    28,    57,    29,    -1,
      -1,    61,    -1,    60,    27,    61,    -1,    13,    34,    62,
      -1,    34,    62,    -1,    14,    -1,    12,    -1,    13,    -1,
      16,    13,    -1,    28,    62,    29,    -1,    62,    22,    62,
      -1,    62,    21,    62,    -1,    62,    23,    62,    -1,    62,
      24,    62,    -1,    62,    25,    62,    -1,    62,    18,    62,
      -1,    62,    19,    62,    -1,    62,    20,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   131,   132,   141,   142,   145,   154,   157,
     162,   169,   170,   173,   178,   181,   182,   183,   186,   187,
     190,   193,   194,   197,   198,   204,   205,   208,   209,   212,
     213,   216,   219,   220,   223,   224,   228,   230,   234,   238,
     239,   240,   242,   243,   244,   246,   250,   254,   255,   256,
     260,   261,   262,   269,   270,   271,   274,   275,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_XFORM", "T_COND", "T_EXISTS", "T_NUM",
  "T_REPEAT", "T_UNIQUE", "T_ENUM", "T_PICK", "T_RESOURCE", "T_LITERAL",
  "T_IDENT", "T_INTEGER", "'?'", "T_DEREF", "'>'", "T_ELLIPSIS", "'V'",
  "'G'", "'-'", "'+'", "'*'", "'/'", "'%'", "':'", "';'", "'('", "')'",
  "','", "'M'", "'R'", "'|'", "'='", "'$'", "'{'", "'}'", "'['", "']'",
  "$accept", "input", "rules", "rule", "transformation", "transopts",
  "transopt", "transcmd", "transaddr", "translist", "mapping", "mapopts",
  "mapopt", "mapaction", "params", "options", "option", "atoms", "atom",
  "atom2", "imperatives", "imperative", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    63,   270,    62,   271,    86,
      71,    45,    43,    42,    47,    37,    58,    59,    40,    41,
      44,    77,    82,   124,    61,    36,   123,   125,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    42,    43,    43,    43,
      44,    45,    45,    46,    47,    48,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    59,    59,    60,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     4,     5,     7,
       5,     2,     1,     3,     4,     1,     3,     0,     2,     0,
       4,     2,     1,     3,     3,     1,     3,     2,     1,     3,
       1,     1,     2,     1,     1,     3,     2,     3,     3,     2,
       3,     2,     2,     2,     3,     6,     6,     2,     2,     6,
       1,     1,     4,     0,     1,     3,     3,     2,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     4,     6,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    51,     0,     0,     0,    53,     0,     0,    22,     0,
      30,    31,    33,    34,    28,     0,     0,     0,    12,    50,
       0,     0,    47,    48,     0,     0,     0,     0,     0,     0,
      41,    36,    39,     0,     0,     0,    54,     0,     0,    20,
      21,     7,     0,    32,     0,    43,    42,    27,     0,    17,
      10,    11,     8,     0,     0,    25,    23,    24,    37,     0,
      38,     0,    59,    60,    58,     0,     0,    57,     0,    40,
      44,    29,    35,     0,    15,    13,     0,     0,     0,     0,
      52,    56,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,    19,     0,     0,     0,    26,
      62,    68,    69,    70,    64,    63,    65,    66,    67,     9,
      16,    19,     0,    46,    45,    49,    18,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,    37,    38,    95,    96,   132,
       9,    27,    28,    76,    35,    29,    30,    31,    32,    33,
      55,    56,    87
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -54
static const yytype_int16 yypact[] =
{
     -54,    12,    75,   -54,    -3,     2,   -19,   -54,   -54,   -54,
       8,    16,    28,    47,     9,    60,    19,    60,    60,    46,
     -28,    31,    60,    60,    64,    -5,    60,     4,   -54,    52,
      49,    60,   123,   -54,   -54,    -2,    78,    67,     9,   -54,
      74,    60,   -54,   -54,    97,   111,   131,    60,    60,    60,
     123,   123,   -54,   110,    71,    34,   -54,   108,   -28,   -54,
     -54,   -54,    60,   123,   135,   -54,   -54,   -54,   124,   137,
     -54,   -54,   -54,    80,   119,   129,   -54,   -54,    99,    10,
     123,    71,   -54,   -54,   -54,   139,    71,   107,    -5,   -54,
     -54,   -54,   -54,    60,   125,   -54,   141,   128,    60,   144,
     -54,   107,   -54,    95,    71,    71,    71,    71,    71,    71,
      71,    71,   -54,   130,   145,   146,   132,   133,    83,   -54,
     -54,   114,    68,    68,    84,    84,   -54,   -54,   -54,   -54,
     -54,   146,   136,   -54,   -54,   -54,   -54,   -54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,   -54,   -54,   122,   -54,   -54,   -54,    33,
     -54,   -54,   138,   -54,   -54,   -13,   -54,   118,   -17,   -54,
     -54,    79,   -53
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      42,    43,    40,    45,    46,    50,    51,    12,    53,    13,
      10,    67,     3,    57,    63,    11,    58,    16,    17,    18,
      19,    36,    39,    21,    73,    22,    23,    68,   101,    54,
      78,    59,    80,   103,    14,    16,    17,    18,    19,   100,
      20,    21,    15,    22,    23,    24,    25,    41,    26,    91,
      47,   121,   122,   123,   124,   125,   126,   127,   128,    48,
      34,    88,    63,    24,    25,    49,    26,    16,    17,    18,
      19,    89,    39,    21,    44,    22,    23,    52,     4,    61,
     113,   118,    62,    82,    83,    84,     5,    85,     6,   107,
     108,   109,   110,   111,    70,    24,    25,    64,    26,    86,
      64,    72,    65,    66,    69,    65,    66,   109,   110,   111,
      97,    74,   135,   104,   105,   106,   107,   108,   109,   110,
     111,    65,    66,    75,   120,   104,   105,   106,   107,   108,
     109,   110,   111,   105,   106,   107,   108,   109,   110,   111,
      64,   116,   117,    77,    81,    65,    66,    90,    92,    98,
      93,    94,   102,    99,   115,   114,   119,   129,   131,   130,
      71,   133,   134,   137,   136,    60,    79,   112
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-54))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      17,    18,    15,    31,    32,    22,    23,    26,    13,    28,
      13,    13,     0,    26,    31,    13,    12,     7,     8,     9,
      10,    12,    12,    13,    41,    15,    16,    29,    81,    34,
      47,    27,    49,    86,    26,     7,     8,     9,    10,    29,
      12,    13,    26,    15,    16,    35,    36,    28,    38,    62,
      19,   104,   105,   106,   107,   108,   109,   110,   111,    28,
      13,    27,    79,    35,    36,    34,    38,     7,     8,     9,
      10,    37,    12,    13,    28,    15,    16,    13,     3,    27,
      93,    98,    33,    12,    13,    14,    11,    16,    13,    21,
      22,    23,    24,    25,    27,    35,    36,    17,    38,    28,
      17,    27,    22,    23,    26,    22,    23,    23,    24,    25,
      30,    14,    29,    18,    19,    20,    21,    22,    23,    24,
      25,    22,    23,    12,    29,    18,    19,    20,    21,    22,
      23,    24,    25,    19,    20,    21,    22,    23,    24,    25,
      17,    13,    14,    12,    34,    22,    23,    39,    13,    30,
      26,    14,    13,    24,    13,    30,    12,    27,    12,    14,
      38,    29,    29,    27,   131,    27,    48,    88
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     3,    11,    13,    43,    44,    50,
      13,    13,    26,    28,    26,    26,     7,     8,     9,    10,
      12,    13,    15,    16,    35,    36,    38,    51,    52,    55,
      56,    57,    58,    59,    13,    54,    12,    45,    46,    12,
      55,    28,    58,    58,    28,    31,    32,    19,    28,    34,
      58,    58,    13,    13,    34,    60,    61,    55,    12,    27,
      52,    27,    33,    58,    17,    22,    23,    13,    29,    26,
      27,    45,    27,    58,    14,    12,    53,    12,    58,    57,
      58,    34,    12,    13,    14,    16,    28,    62,    27,    37,
      39,    55,    13,    26,    14,    47,    48,    30,    30,    24,
      29,    62,    13,    62,    18,    19,    20,    21,    22,    23,
      24,    25,    61,    55,    30,    13,    13,    14,    58,    12,
      29,    62,    62,    62,    62,    62,    62,    62,    62,    27,
      14,    12,    49,    29,    29,    29,    49,    27
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 111 "parser.y"
    { use_rtn((yyvsp[(1) - (1)].r));
  /* if(dump_rtn) { 
                 dump_rules($1); 
		 dump_mappings(mappings); 
		 dump_transformations(transformations);
	       }
	       check_rtn($1);
               rule_base = $1;
	       if(start_symbol) {
		 initial_rule=rule_find($1, start_symbol);
		 if(!initial_rule) {
		   fprintf(stderr, "rule \"%s\" does not exist.\n", 
			   start_symbol);
		   exit(1);
		 };
	       };
	       if(!inhibit) fprintf(outfile, "%s\n", 
				    resolve_rule($1, initial_rule)); */}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 131 "parser.y"
    { (yyval.r) = NULL; }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 132 "parser.y"
    { 
/*	              if(initial_rule==NULL) {
			initial_rule = $2;
			if(verbose)fprintf(stderr, "Start symbol == %s\n", 
				initial_rule->symbol);
		      };*/
		      /* FIXME: add check for duplicate rules here */
	              (yyval.r) = rule_insert((yyvsp[(1) - (2)].r), (yyvsp[(2) - (2)].r)); 
		    }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 141 "parser.y"
    { (yyval.r) = (yyvsp[(1) - (2)].r); /* mappings != rules */ }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 142 "parser.y"
    { (yyval.r) = (yyvsp[(1) - (2)].r); /* mappings != rules */ }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 145 "parser.y"
    { pRule r = rule_new((yyvsp[(1) - (4)].s), (yyvsp[(3) - (4)].o), NULL); 
                                if(initial_rule==NULL) {
           			  initial_rule = r;
			          if(verbose)
                                    fprintf(stderr, "Start symbol == %s\n", 
				                    r->symbol);
		                };
			        (yyval.r) = r;
			      }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 154 "parser.y"
    { pRule r = rule_new((yyvsp[(2) - (5)].s), (yyvsp[(4) - (5)].o), NULL); 
			                   (yyval.r) = r;
			                 }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 157 "parser.y"
    { pRule r = rule_new((yyvsp[(1) - (7)].s), (yyvsp[(6) - (7)].o), (yyvsp[(3) - (7)].p)); 
					       (yyval.r) = r;
					     }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 162 "parser.y"
    { 
  transformations = list_cons(new_transformation((yyvsp[(2) - (5)].s), (yyvsp[(4) - (5)].l)), transformations); 
/*  fprintf(stderr, "Transformation: %s\n", 
	 ((pTransformation)transformations->data)->name);*/
}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 169 "parser.y"
    { (yyval.l) = list_cons((yyvsp[(1) - (2)].to), (yyvsp[(2) - (2)].l)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 170 "parser.y"
    { (yyval.l) = list_cons((yyvsp[(1) - (1)].to), NULL); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 173 "parser.y"
    { (yyval.to) = new_transopt((yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].tc));
/*				   fprintf(stderr, "xform option: %s", $1);*/
				 }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 178 "parser.y"
    { (yyval.tc) = new_transcmd((yyvsp[(1) - (4)].pi), (yyvsp[(2) - (4)].s), (yyvsp[(3) - (4)].l)); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 181 "parser.y"
    { (yyval.pi) = new_addr_range((yyvsp[(1) - (1)].i), (yyvsp[(1) - (1)].i)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 182 "parser.y"
    { (yyval.pi) = new_addr_range((yyvsp[(1) - (3)].i), (yyvsp[(3) - (3)].i)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 183 "parser.y"
    { (yyval.pi) = NULL; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 186 "parser.y"
    { (yyval.l) = list_cons((void *)(yyvsp[(1) - (2)].s), (yyvsp[(2) - (2)].l)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { (yyval.l) = NULL; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 190 "parser.y"
    { mappings = map_cons((yyvsp[(1) - (4)].s), (yyvsp[(3) - (4)].mo), mappings); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 193 "parser.y"
    { (yyval.mo) = mapopt_concat((yyvsp[(1) - (2)].mo), (yyvsp[(2) - (2)].mo)); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 194 "parser.y"
    { (yyval.mo) = (yyvsp[(1) - (1)].mo); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 197 "parser.y"
    { (yyval.mo) = mapopt_cons((yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].ma), NULL); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 198 "parser.y"
    { 
    (yyval.mo) = mapopt_cons((yyvsp[(1) - (3)].s), new_replace_action((yyvsp[(3) - (3)].s)),
		     mapopt_cons((yyvsp[(3) - (3)].s), new_replace_action((yyvsp[(1) - (3)].s)), NULL));
  }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 204 "parser.y"
    { (yyval.ma) = new_replace_action((yyvsp[(1) - (1)].s)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 205 "parser.y"
    { (yyval.ma) = new_subst_action((yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].s)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 208 "parser.y"
    { (yyval.p) = list_append((yyvsp[(1) - (2)].p), list_cons((void *)(yyvsp[(2) - (2)].s), NULL)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 209 "parser.y"
    { (yyval.p) = list_cons((void *)(yyvsp[(1) - (1)].s), NULL); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 212 "parser.y"
    { (yyval.o) = option_append((yyvsp[(1) - (3)].o), (yyvsp[(3) - (3)].o)); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 213 "parser.y"
    { (yyval.o) = (yyvsp[(1) - (1)].o); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 216 "parser.y"
    { (yyval.o) = option_cons((yyvsp[(1) - (1)].n), NULL); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 219 "parser.y"
    { (yyval.n) = node_append((yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 220 "parser.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 223 "parser.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 224 "parser.y"
    { pNode n = node_cons(mapping, (yyvsp[(3) - (3)].s), NULL);
			  n->params = (yyvsp[(1) - (3)].n);
			  (yyval.n) = n;
			}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 228 "parser.y"
    { pNode n = node_cons(deref, NULL, NULL); 
		     n->params=(yyvsp[(2) - (2)].n); (yyval.n)=n; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 230 "parser.y"
    { pNode n = node_cons(var_conddef, (yyvsp[(1) - (3)].s), NULL);
			 n->params = (yyvsp[(3) - (3)].n);
			 (yyval.n) = n;
		       }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 234 "parser.y"
    { pNode n = node_cons(var_def, (yyvsp[(1) - (3)].s), NULL);
			 n->params = (yyvsp[(3) - (3)].n);
			 (yyval.n) = n;
		       }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 238 "parser.y"
    { (yyval.n) = node_cons(var_ref, (yyvsp[(2) - (2)].s), NULL); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 239 "parser.y"
    { (yyval.n) = node_cons(code, (char *)(yyvsp[(2) - (3)].c), NULL); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 240 "parser.y"
    { pNode n = node_cons(silence, NULL, NULL); n->params=(yyvsp[(2) - (2)].n); 
		 (yyval.n) = n; }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 242 "parser.y"
    { pNode n = node_cons(star, NULL, NULL); n->params=(yyvsp[(1) - (2)].n); (yyval.n)=n; }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 243 "parser.y"
    { pNode n = node_cons(plus, NULL, NULL); n->params=(yyvsp[(1) - (2)].n); (yyval.n)=n; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 244 "parser.y"
    { pNode n = node_cons(choice, (char *)(yyvsp[(2) - (3)].o), NULL);
                        n->last_choice = -1; (yyval.n)=n; }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 246 "parser.y"
    { 
      pNode n = node_cons(repeat_const, NULL, NULL);
      n->params = (yyvsp[(3) - (6)].n); n->int_param = (yyvsp[(5) - (6)].i);
      (yyval.n)=n; }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 250 "parser.y"
    { 
      pNode n = node_cons(repeat_var, NULL, NULL);
      n->params = (yyvsp[(3) - (6)].n); n->data = (yyvsp[(5) - (6)].s);
      (yyval.n)=n; }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 254 "parser.y"
    { pNode n=(yyvsp[(2) - (2)].n); n->mode = unique; (yyval.n)=n; }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 255 "parser.y"
    { pNode n=(yyvsp[(2) - (2)].n); n->mode = enumerate; (yyval.n)=n; }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 256 "parser.y"
    { pNode n=(yyvsp[(5) - (6)].n); n->mode = pick; 
                                          n->pick_num=(yyvsp[(3) - (6)].i); (yyval.n)=n; }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 260 "parser.y"
    { (yyval.n) = node_cons(literal, (yyvsp[(1) - (1)].s), NULL); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 261 "parser.y"
    { (yyval.n) = node_cons(symbol, (yyvsp[(1) - (1)].s), NULL); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 262 "parser.y"
    { pNode n = node_cons(symbol, (yyvsp[(1) - (4)].s), NULL);
			      n->params = (yyvsp[(3) - (4)].n);
			      (yyval.n) = n;
			    }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 269 "parser.y"
    { (yyval.c) = NULL; }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 270 "parser.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 271 "parser.y"
    { (yyval.c) = icat((yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c)); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 274 "parser.y"
    { (yyval.c) = icat((yyvsp[(3) - (3)].c), e_set((yyvsp[(1) - (3)].s))); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 275 "parser.y"
    { (yyval.c) = icat((yyvsp[(2) - (2)].c), e_simple(EMIT)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 278 "parser.y"
    { (yyval.c) = e_push_int((yyvsp[(1) - (1)].i)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 279 "parser.y"
    { (yyval.c) = e_push_str((yyvsp[(1) - (1)].s)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 280 "parser.y"
    { (yyval.c) = e_pushv((yyvsp[(1) - (1)].s)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 281 "parser.y"
    { (yyval.c) = e_invoke((yyvsp[(2) - (2)].s)); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 282 "parser.y"
    { (yyval.c) = (yyvsp[(2) - (3)].c); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 283 "parser.y"
    { (yyval.c) = icat((yyvsp[(1) - (3)].c), icat((yyvsp[(3) - (3)].c), e_simple(ADD))); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 284 "parser.y"
    { (yyval.c) = icat((yyvsp[(1) - (3)].c), icat((yyvsp[(3) - (3)].c), e_simple(SUB))); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 285 "parser.y"
    { (yyval.c) = icat((yyvsp[(1) - (3)].c), icat((yyvsp[(3) - (3)].c), e_simple(MUL))); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 286 "parser.y"
    { (yyval.c) = icat((yyvsp[(1) - (3)].c), icat((yyvsp[(3) - (3)].c), e_simple(DIV))); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 287 "parser.y"
    { (yyval.c) = icat((yyvsp[(1) - (3)].c), icat((yyvsp[(3) - (3)].c), e_simple(MOD))); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 288 "parser.y"
    { (yyval.c) = icat((yyvsp[(1) - (3)].c), icat((yyvsp[(3) - (3)].c), e_simple(RANDOM))); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 289 "parser.y"
    { (yyval.c) = icat((yyvsp[(1) - (3)].c), icat((yyvsp[(3) - (3)].c), e_simple(LESSER))); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 290 "parser.y"
    { (yyval.c) = icat((yyvsp[(1) - (3)].c), icat((yyvsp[(3) - (3)].c), e_simple(GREATER))); }
    break;



/* Line 1806 of yacc.c  */
#line 2099 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 293 "parser.y"


extern int cur_line;
extern char cur_file[1024];

yyerror(char *s)
{
  fprintf(stderr, "%s:%i: %s\n", cur_file, cur_line, s);
};

#if 0

int strtoseed(char *s)
{
    int r=0;
    if(atoi(s))return atoi(s);
    while(*s) { r+=*(s++); }
    return r;
};

main(int argc, char *argv[])
{
  int i;

  char *rseed=NULL; /* a random seed, in string form */

  for(i=1; i<argc; i++) {
    if(*(argv[i])=='-')
      switch(argv[i][1]) {
      case 'd': dump_rtn = 1;
      case 'i': inhibit = 1; break;
      case 'o': outfile=fopen(argv[++i], "w"); break;
      case 'p': old_probability=1; break;
      case 'r': rseed = argv[++i]; break;
      case 's': start_symbol = argv[++i]; break;
      case 't': trace=1; break;
      case 'v': verbose = 1; break;
      case 'y': yydebug=1; break;
      };
  };
  srandom(rseed?strtoseed(rseed):time(NULL));
  yyparse();
};

#endif

