#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h"

typedef struct {
    char nome[15];
    float valor;
} Variavel;


void criarVar(const char *arquivo, const char *variavel, float valor) {
    FILE *arq = fopen(arquivo, "ab");

    Variavel var;
    strncpy(var.nome, variavel, 14);
    var.nome[14] = '\0'; // coloca o terminador no ultimo espaço
    var.valor = valor;

    fwrite(&var, sizeof(Variavel), 1, arq);
    fclose(arq);
}

void altVar(const char *arquivo, const char *variavel, float valor) {
    FILE *arq = fopen(arquivo, "r+b");

    Variavel var;
    while (fread(&var, sizeof(Variavel), 1, arq)) {
        if (strcmp(var.nome, variavel) == 0) {
            var.valor = valor;
            fseek(arq, -sizeof(Variavel), SEEK_CUR); // tem que voltar pro começo
            fwrite(&var, sizeof(Variavel), 1, arq); // so atualiza aqui
            break;
        }
    }

    fclose(arq);
}

float lerVar(const char *arquivo, const char *variavel) {
    FILE *arq = fopen(arquivo, "rb");

    Variavel var;
    while (fread(&var, sizeof(Variavel), 1, arq)) {
        if (strcmp(var.nome, variavel) == 0) {
            fclose(arq);
            return var.valor; 
        }
    }
    
    fclose(arq);
    return 0; // se nn achou a variavel retorna 0
}