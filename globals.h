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

#endif
