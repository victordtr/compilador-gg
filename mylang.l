%option noyywrap

%{
#include "globals.h"
#include "util.h"
#include "scan.h"

char lexema[TAM_LEXEMA + 1];
%}

	/* regras */

identificador		[a-zA-Z_][a-zA-Z0-9_]*
numero			[+-]?[0-9][0-9]*
	/* exp			[eE][0-9]+
	real			[+-]?[0-9]*\.[0-9]+{exp}?
	octal			[+-]?0[0-7][0-7]*
	hexadecimal		[+-]?0x[0-9a-fA-F][0-9a-fA-F]* */
newline			\n
whitespace		[ \t\r]+
endcmd			";"

%%

	/* KEYWORDS */
"if"			{return IF;}
"else"			{return ELSE;}
"loop"			{return LOOP;}
"read"			{return READ;}
"print"			{return PRINT;}

{identificador}		{return ID;}
{numero}		{return NUM;}
{whitespace}		{/* skip */}
{newline}		{numline++;}

	/* COMPARADORES */
"=="			{return EQ;}
"<"			{return LT;}
">"			{return GT;}
"<="			{return LE;}
">="			{return GE;}
"~="			{return NE;}

	/* OPERADORES MATEMATICOS */
"="            		{return ASSIGN;}
"+"             	{return PLUS;}
"-"             	{return MINUS;}
"*"             	{return TIMES;}
"/"             	{return OVER;}
"**"			{return POW;}
"%"			{return MODULE;}

	/* OPERADORES LOGICOS */
"&"			{return AND;}
"|"			{return OR;}
"^"			{return XOR;}
"~"			{return NOT;}

	/* OPERADORES LOGICOS DE EQUACOES CONDICIONAIS */
"and"			{return CAND;}
"or"			{return COR;}

	/* BLOCOS E ESPECIAIS */
"{"			{return LCHAVES;}
"}"			{return RCHAVES;}
"("			{return LPAREN;}
")"			{return RPAREN;}
{endcmd}		{return ENDCMD;}
"\"" {
	char c;
	do {
		c = input();
		if (c == EOF) break;
		if (c == '\n') numline++;
	} while (c != '\"');
}


	/* COMENTARIOS */
"#" {
	char c;
	do {
		c = input();
		if (c == EOF) break;
		if (c == '\n') numline++;
	} while (c != '\n');
}

	/* Colocar depois que nem python
 	para multiplos comentarios ''' blabla ''' ?? */

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
