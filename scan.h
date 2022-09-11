#ifndef _SCAN_H_
#define _SCAN_H_

#include "globals.h"

/* TAM_LEXEMA eh o tamanho maximo de um token */
#define TAM_LEXEMA 63

/* lexema armazena o lexema de cada token */
extern char lexema[TAM_LEXEMA + 1];

/* retorna o proximo token do arquivo fonte */
TokenType getToken();

#endif
