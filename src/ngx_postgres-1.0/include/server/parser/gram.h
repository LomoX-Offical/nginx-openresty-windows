
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
     IDENT = 258,
     FCONST = 259,
     SCONST = 260,
     BCONST = 261,
     XCONST = 262,
     Op = 263,
     ICONST = 264,
     PARAM = 265,
     TYPECAST = 266,
     DOT_DOT = 267,
     COLON_EQUALS = 268,
     ABORT_P = 269,
     ABSOLUTE_P = 270,
     ACCESS = 271,
     ACTION = 272,
     ADD_P = 273,
     ADMIN = 274,
     AFTER = 275,
     AGGREGATE = 276,
     ALL = 277,
     ALSO = 278,
     ALTER = 279,
     ALWAYS = 280,
     ANALYSE = 281,
     ANALYZE = 282,
     AND = 283,
     ANY = 284,
     ARRAY = 285,
     AS = 286,
     ASC = 287,
     ASSERTION = 288,
     ASSIGNMENT = 289,
     ASYMMETRIC = 290,
     AT = 291,
     ATTRIBUTE = 292,
     AUTHORIZATION = 293,
     BACKWARD = 294,
     BEFORE = 295,
     BEGIN_P = 296,
     BETWEEN = 297,
     BIGINT = 298,
     BINARY = 299,
     BIT = 300,
     BOOLEAN_P = 301,
     BOTH = 302,
     BY = 303,
     CACHE = 304,
     CALLED = 305,
     CASCADE = 306,
     CASCADED = 307,
     CASE = 308,
     CAST = 309,
     CATALOG_P = 310,
     CHAIN = 311,
     CHAR_P = 312,
     CHARACTER = 313,
     CHARACTERISTICS = 314,
     CHECK = 315,
     CHECKPOINT = 316,
     CLASS = 317,
     CLOSE = 318,
     CLUSTER = 319,
     COALESCE = 320,
     COLLATE = 321,
     COLLATION = 322,
     COLUMN = 323,
     COMMENT = 324,
     COMMENTS = 325,
     COMMIT = 326,
     COMMITTED = 327,
     CONCURRENTLY = 328,
     CONFIGURATION = 329,
     CONNECTION = 330,
     CONSTRAINT = 331,
     CONSTRAINTS = 332,
     CONTENT_P = 333,
     CONTINUE_P = 334,
     CONVERSION_P = 335,
     COPY = 336,
     COST = 337,
     CREATE = 338,
     CROSS = 339,
     CSV = 340,
     CURRENT_P = 341,
     CURRENT_CATALOG = 342,
     CURRENT_DATE = 343,
     CURRENT_ROLE = 344,
     CURRENT_SCHEMA = 345,
     CURRENT_TIME = 346,
     CURRENT_TIMESTAMP = 347,
     CURRENT_USER = 348,
     CURSOR = 349,
     CYCLE = 350,
     DATA_P = 351,
     DATABASE = 352,
     DAY_P = 353,
     DEALLOCATE = 354,
     DEC = 355,
     DECIMAL_P = 356,
     DECLARE = 357,
     DEFAULT = 358,
     DEFAULTS = 359,
     DEFERRABLE = 360,
     DEFERRED = 361,
     DEFINER = 362,
     DELETE_P = 363,
     DELIMITER = 364,
     DELIMITERS = 365,
     DESC = 366,
     DICTIONARY = 367,
     DISABLE_P = 368,
     DISCARD = 369,
     DISTINCT = 370,
     DO = 371,
     DOCUMENT_P = 372,
     DOMAIN_P = 373,
     DOUBLE_P = 374,
     DROP = 375,
     EACH = 376,
     ELSE = 377,
     ENABLE_P = 378,
     ENCODING = 379,
     ENCRYPTED = 380,
     END_P = 381,
     ENUM_P = 382,
     ESCAPE = 383,
     EXCEPT = 384,
     EXCLUDE = 385,
     EXCLUDING = 386,
     EXCLUSIVE = 387,
     EXECUTE = 388,
     EXISTS = 389,
     EXPLAIN = 390,
     EXTENSION = 391,
     EXTERNAL = 392,
     EXTRACT = 393,
     FALSE_P = 394,
     FAMILY = 395,
     FETCH = 396,
     FIRST_P = 397,
     FLOAT_P = 398,
     FOLLOWING = 399,
     FOR = 400,
     FORCE = 401,
     FOREIGN = 402,
     FORWARD = 403,
     FREEZE = 404,
     FROM = 405,
     FULL = 406,
     FUNCTION = 407,
     FUNCTIONS = 408,
     GLOBAL = 409,
     GRANT = 410,
     GRANTED = 411,
     GREATEST = 412,
     GROUP_P = 413,
     HANDLER = 414,
     HAVING = 415,
     HEADER_P = 416,
     HOLD = 417,
     HOUR_P = 418,
     IDENTITY_P = 419,
     IF_P = 420,
     ILIKE = 421,
     IMMEDIATE = 422,
     IMMUTABLE = 423,
     IMPLICIT_P = 424,
     IN_P = 425,
     INCLUDING = 426,
     INCREMENT = 427,
     INDEX = 428,
     INDEXES = 429,
     INHERIT = 430,
     INHERITS = 431,
     INITIALLY = 432,
     INLINE_P = 433,
     INNER_P = 434,
     INOUT = 435,
     INPUT_P = 436,
     INSENSITIVE = 437,
     INSERT = 438,
     INSTEAD = 439,
     INT_P = 440,
     INTEGER = 441,
     INTERSECT = 442,
     INTERVAL = 443,
     INTO = 444,
     INVOKER = 445,
     IS = 446,
     ISNULL = 447,
     ISOLATION = 448,
     JOIN = 449,
     KEY = 450,
     LABEL = 451,
     LANGUAGE = 452,
     LARGE_P = 453,
     LAST_P = 454,
     LC_COLLATE_P = 455,
     LC_CTYPE_P = 456,
     LEADING = 457,
     LEAST = 458,
     LEFT = 459,
     LEVEL = 460,
     LIKE = 461,
     LIMIT = 462,
     LISTEN = 463,
     LOAD = 464,
     LOCAL = 465,
     LOCALTIME = 466,
     LOCALTIMESTAMP = 467,
     LOCATION = 468,
     LOCK_P = 469,
     MAPPING = 470,
     MATCH = 471,
     MAXVALUE = 472,
     MINUTE_P = 473,
     MINVALUE = 474,
     MODE = 475,
     MONTH_P = 476,
     MOVE = 477,
     NAME_P = 478,
     NAMES = 479,
     NATIONAL = 480,
     NATURAL = 481,
     NCHAR = 482,
     NEXT = 483,
     NO = 484,
     NONE = 485,
     NOT = 486,
     NOTHING = 487,
     NOTIFY = 488,
     NOTNULL = 489,
     NOWAIT = 490,
     NULL_P = 491,
     NULLIF = 492,
     NULLS_P = 493,
     NUMERIC = 494,
     OBJECT_P = 495,
     OF = 496,
     OFF = 497,
     OFFSET = 498,
     OIDS = 499,
     ON = 500,
     ONLY = 501,
     OPERATOR = 502,
     OPTION = 503,
     OPTIONS = 504,
     OR = 505,
     ORDER = 506,
     OUT_P = 507,
     OUTER_P = 508,
     OVER = 509,
     OVERLAPS = 510,
     OVERLAY = 511,
     OWNED = 512,
     OWNER = 513,
     PARSER = 514,
     PARTIAL = 515,
     PARTITION = 516,
     PASSING = 517,
     PASSWORD = 518,
     PLACING = 519,
     PLANS = 520,
     POSITION = 521,
     PRECEDING = 522,
     PRECISION = 523,
     PRESERVE = 524,
     PREPARE = 525,
     PREPARED = 526,
     PRIMARY = 527,
     PRIOR = 528,
     PRIVILEGES = 529,
     PROCEDURAL = 530,
     PROCEDURE = 531,
     QUOTE = 532,
     RANGE = 533,
     READ = 534,
     REAL = 535,
     REASSIGN = 536,
     RECHECK = 537,
     RECURSIVE = 538,
     REF = 539,
     REFERENCES = 540,
     REINDEX = 541,
     RELATIVE_P = 542,
     RELEASE = 543,
     RENAME = 544,
     REPEATABLE = 545,
     REPLACE = 546,
     REPLICA = 547,
     RESET = 548,
     RESTART = 549,
     RESTRICT = 550,
     RETURNING = 551,
     RETURNS = 552,
     REVOKE = 553,
     RIGHT = 554,
     ROLE = 555,
     ROLLBACK = 556,
     ROW = 557,
     ROWS = 558,
     RULE = 559,
     SAVEPOINT = 560,
     SCHEMA = 561,
     SCROLL = 562,
     SEARCH = 563,
     SECOND_P = 564,
     SECURITY = 565,
     SELECT = 566,
     SEQUENCE = 567,
     SEQUENCES = 568,
     SERIALIZABLE = 569,
     SERVER = 570,
     SESSION = 571,
     SESSION_USER = 572,
     SET = 573,
     SETOF = 574,
     SHARE = 575,
     SHOW = 576,
     SIMILAR = 577,
     SIMPLE = 578,
     SMALLINT = 579,
     SOME = 580,
     STABLE = 581,
     STANDALONE_P = 582,
     START = 583,
     STATEMENT = 584,
     STATISTICS = 585,
     STDIN = 586,
     STDOUT = 587,
     STORAGE = 588,
     STRICT_P = 589,
     STRIP_P = 590,
     SUBSTRING = 591,
     SYMMETRIC = 592,
     SYSID = 593,
     SYSTEM_P = 594,
     TABLE = 595,
     TABLES = 596,
     TABLESPACE = 597,
     TEMP = 598,
     TEMPLATE = 599,
     TEMPORARY = 600,
     TEXT_P = 601,
     THEN = 602,
     TIME = 603,
     TIMESTAMP = 604,
     TO = 605,
     TRAILING = 606,
     TRANSACTION = 607,
     TREAT = 608,
     TRIGGER = 609,
     TRIM = 610,
     TRUE_P = 611,
     TRUNCATE = 612,
     TRUSTED = 613,
     TYPE_P = 614,
     UNBOUNDED = 615,
     UNCOMMITTED = 616,
     UNENCRYPTED = 617,
     UNION = 618,
     UNIQUE = 619,
     UNKNOWN = 620,
     UNLISTEN = 621,
     UNLOGGED = 622,
     UNTIL = 623,
     UPDATE = 624,
     USER = 625,
     USING = 626,
     VACUUM = 627,
     VALID = 628,
     VALIDATE = 629,
     VALIDATOR = 630,
     VALUE_P = 631,
     VALUES = 632,
     VARCHAR = 633,
     VARIADIC = 634,
     VARYING = 635,
     VERBOSE = 636,
     VERSION_P = 637,
     VIEW = 638,
     VOLATILE = 639,
     WHEN = 640,
     WHERE = 641,
     WHITESPACE_P = 642,
     WINDOW = 643,
     WITH = 644,
     WITHOUT = 645,
     WORK = 646,
     WRAPPER = 647,
     WRITE = 648,
     XML_P = 649,
     XMLATTRIBUTES = 650,
     XMLCONCAT = 651,
     XMLELEMENT = 652,
     XMLEXISTS = 653,
     XMLFOREST = 654,
     XMLPARSE = 655,
     XMLPI = 656,
     XMLROOT = 657,
     XMLSERIALIZE = 658,
     YEAR_P = 659,
     YES_P = 660,
     ZONE = 661,
     NULLS_FIRST = 662,
     NULLS_LAST = 663,
     WITH_TIME = 664,
     POSTFIXOP = 665,
     UMINUS = 666
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 160 "gram.y"

	core_YYSTYPE		core_yystype;
	/* these fields must match core_YYSTYPE: */
	int					ival;
	char				*str;
	const char			*keyword;

	char				chr;
	bool				boolean;
	JoinType			jtype;
	DropBehavior		dbehavior;
	OnCommitAction		oncommit;
	List				*list;
	Node				*node;
	Value				*value;
	ObjectType			objtype;
	TypeName			*typnam;
	FunctionParameter   *fun_param;
	FunctionParameterMode fun_param_mode;
	FuncWithArgs		*funwithargs;
	DefElem				*defelt;
	SortBy				*sortby;
	WindowDef			*windef;
	JoinExpr			*jexpr;
	IndexElem			*ielem;
	Alias				*alias;
	RangeVar			*range;
	IntoClause			*into;
	WithClause			*with;
	A_Indices			*aind;
	ResTarget			*target;
	struct PrivTarget	*privtarget;
	AccessPriv			*accesspriv;
	InsertStmt			*istmt;
	VariableSetStmt		*vsetstmt;



/* Line 1676 of yacc.c  */
#line 502 "gram.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif



#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



