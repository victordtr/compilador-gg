#include "globals.h"
#include "util.h"

void printToken(TokenType token, const char* lexema)
{
    switch (token) {
        // keywords
        case IF:
        case ELSE:
        case LOOP:
        case READ:
        case PRINT: fprintf(lstfile, "keyword: %s\n", lexema); break;
        // tokens multicaracteres
        case ID:    fprintf(lstfile, "ID,\tname= %s\n", lexema); break;
        case INT:   fprintf(lstfile, "INT\tval= %s\n", lexema); break;
        case REAL:  fprintf(lstfile, "REAL\tval= %s\n", lexema); break;
        case STRING:    fprintf(lstfile, "STRING\tval= %s\n", lexema); break;
        // comparadores
        case EQ:
        case LT:
        case GT:
        case LE:
        case GE:
        case NE:
        // operadores matematicos
        case ASSIGN:
        case PLUS:
        case MINUS:
        case TIMES:
        case OVER:
        case POW:
        case MODULE:
        // operadores logicos
        case AND:
        case OR:
        case XOR:
        case NOT:
        // operadores logicos de equacoes condicionais
        case CAND:
        case COR:
        // blocos e especiais
        case LCHAVES:
        case RCHAVES:
        case LPAREN:
        case RPAREN:
        case ENDCMD:    fprintf(lstfile, "%s\n", lexema); break;
        case ENDFILE:   fprintf(lstfile, "EOF\n"); break;
        case ERROR:     fprintf(lstfile, "ERROR: %s\n", lexema); break;
        default:
            fprintf(lstfile, "Unknown token\n");
    }
}
