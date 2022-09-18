#include "util.c"
#include "lex.yy.c"

FILE *srcfile, *lstfile;
int numline = 0;

int EchoSource = FALSE;
int TraceScan = TRUE;
int TraceParse = FALSE;
int TraceAnalyze = FALSE;
int TraceCode = FALSE;

int main(int argc, char* argv[])
{
    // programa analisa apenas um arquivo fonte por vez
    if (argc != 2) {
        printf("error: should use 1 input file\n");
        return 1;
    }
    if ((srcfile = fopen(argv[1], "r")) == NULL) {
        perror("error: input file does not exist\n");
        return 1;
    }
    if ((lstfile = fopen("listing.txt", "w")) == NULL) {
        fclose(srcfile);
        perror("error: listing.txt will not open\n");
        return 1;
    }

    printf("executando analise lexica de %s\n", argv[1]);
    TokenType token = getToken();
    while (token != ENDFILE) {
        token = getToken();
    }

    fclose(srcfile);
    fclose(lstfile);
    printf("análise terminada\n");
    printf("resultado em listing.txt\n");
    return 0;
}
