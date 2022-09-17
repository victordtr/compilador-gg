#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

typedef enum {
    // TOKENS DE CONTROLE
    ENDFILE, ERROR,
    // KEYWORDS
    IF, ELSE, LOOP, READ, PRINT,
    // TOKENS MULTICARACTERES
    ID, INT, REAL, STRING, BOOL,
    // COMPARADORES
    EQ, LT, GT, LE, GE, NE,
    // OPERADORES MATEMATICOS
    ASSIGN, PLUS, MINUS, TIMES, OVER, POW, MODULE,
    // OPERADORES LOGICOS
    AND, OR, XOR, NOT,
    // OPERADORES LOGICOS DE EQUACOES CONDICIONAIS
    CAND, COR,
    // BLOCOS E ESPECIAIS
    LCHAVES, RCHAVES, LPAREN, RPAREN, ENDCMD
} TokenType;

extern FILE* srcfile;
extern FILE* lstfile;
extern int numline;

#define MAXCHILDREN 3

/*****************************************************/
/***********   Flags para rastreamento    ************/
/*****************************************************/

/* EchoSource = TRUE faz o programa fonte ser impresso no
   arquivo listing com o numero de linha durante a analise
   sintatica */
extern int EchoSource;

/* TraceScan = TRUE faz a informacao do token ser impressa
   quando cada token eh reconhecido pela varredura */
extern int TraceScan;

/* TraceParse = TRUE faz a arvore sintatica ser impressa
   de forma linearizada (identada por filho) */
extern int TraceParse;

/* TraceAnalyze = TRUE faz a insercao e a busca na
   tabela de simbolos serem mostradas no arquivo listing */
extern int TraceAnalyze;

/* TraceCode = TRUE faz os comentarios serem gravados no
   arquivo de codigo da maquina alvo quando o codigo eh gerado */
extern int TraceCode;

/* Error = TRUE previne passadas futuras se ocorrer um erro */
extern int Error;

#endif
