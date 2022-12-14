%option noyywrap

%{
#include "globals.h"
#include "util.h"
#include "scan.h"

char lexema[TAM_LEXEMA + 1];
%}

	/* regras */

identificador	[a-zA-Z_][a-zA-Z0-9_]*
inteiro			[+-]?[0-9][0-9]*
exp				[eE][0-9]+
real			[+-]?[0-9]*\.[0-9]+{exp}?
	/* octal			[+-]?0[0-7][0-7]*
	hexadecimal		[+-]?0[xX][0-9a-fA-F][0-9a-fA-F]* */
newline			\n
whitespace		[ \t\r]+

%%

	/* KEYWORDS */
"if"			{return IF;}
"else"			{return ELSE;}
"loop"			{return LOOP;}
"read"			{return READ;}
"print"			{return PRINT;}
("true"|"false")	{return BOOL;}

	/* OPERADORES LOGICOS DE EQUACOES CONDICIONAIS */
"and"			{return CAND;}
"or"			{return COR;}

{identificador}		{return ID;}
{inteiro}		{return INT;}
{real}			{return REAL;}
{whitespace}		{/* skip */}
{newline}		{numline++;}

	/* COMPARADORES */
"=="			{return EQ;}
"<"				{return LT;}
">"				{return GT;}
"<="			{return LE;}
">="			{return GE;}
"~="			{return NE;}

	/* OPERADORES MATEMATICOS */
"="            	{return ASSIGN;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return TIMES;}
"/"             {return OVER;}
"**"			{return POW;}
"%"				{return MODULE;}

	/* OPERADORES LOGICOS */
"&"				{return AND;}
"|"				{return OR;}
"^"				{return XOR;}
"~"				{return NOT;}

	/* BLOCOS E ESPECIAIS */
"{"				{return LCHAVES;}
"}"				{return RCHAVES;}
"("				{return LPAREN;}
")"				{return RPAREN;}
";"				{return ENDCMD;}

\"[^\"]*\"		{return STRING;}

	/* COMENTARIOS */
"#" {
	char c;
	do {
		c = input();
		if (c == EOF) break;
		if (c == '\n') numline++;
	} while (c != '\n');
}

.			{return ERROR;}

%%

TokenType getToken()
{
	static int onstart = TRUE;
	if (onstart) {
		onstart = FALSE;
		numline++;
		yyin = srcfile;
		yyout = lstfile;
	}

	TokenType tkn_atual = yylex();
	strncpy(lexema, yytext, TAM_LEXEMA);

	if (TraceScan) {
		fprintf(lstfile, "%3d:\t", numline);
		printToken(tkn_atual, lexema);
	}

	return tkn_atual;
}
