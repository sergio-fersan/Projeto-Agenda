#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h"

typedef struct {
    char nome[15];
    float valor;
} Variavel;

typedef struct {
    char nome[15];
    char string[70];
} VarString;

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}menuAgenda

void criarVarBin(const char *arquivo, const char *variavel, float valor) {
    FILE *arq = fopen(arquivo, "ab");

    Variavel var;
    strncpy(var.nome, variavel, 14);
    var.nome[14] = '\0'; // coloca o terminador no ultimo espaço
    var.valor = valor;

    fwrite(&var, sizeof(Variavel), 1, arq);
    fclose(arq);
}

void altVarBin(const char *arquivo, const char *variavel, float valor) {
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

float lerVarBin(const char *arquivo, const char *variavel) {
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

void escVar(const char *arquivo, const char *variavel, float valor){ // escrever em txt
    FILE *arq = fopen(arquivo, "r");
    
    int achouVar = 0; // diz se achou a variavel no txt
    char linha[100];
    char buffer[200] = "";

    while(fgets(linha, sizeof(linha), arq)){
        char tmpVar[15];
        float tmpVal;
        
        if(sscanf(linha, "%[^ ] %f", tmpVar, &tmpVal) == 2){
            if(strcmp(tmpVar, variavel) != 0){ // se as variaveis forem dif
                snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "%s %f\n", tmpVar, tmpVal);
            } else{
                snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "%s %f\n", tmpVar, valor);
                achouVar = 1;
            }
        } else{
            strncat(buffer, linha, sizeof(buffer) - strlen(buffer) - 1); // deixa a linha igual se nn for usar
        }
    } // nada disso ta escrevendo ainda, so armazenando em variavel
    fclose(arq);

    if(achouVar == 1){
        arq = fopen(arquivo, "w");
        fputs(buffer, arq);
        fclose(arq);
    }
}

float lerVar(const char *arquivo, const char *variavel){ // ler em txt
    FILE *arq = fopen(arquivo, "r");

    char linha[100];

    while(fgets(linha, sizeof(linha), arq)){
        char tmpVar[15];
        float tmpVal;

        if(sscanf(linha, "%[^ ] %f", tmpVar, &tmpVal) == 2){  // %[^ ] procura até o espaço, %d lê o valor da variável
            if(strcmp(tmpVar, variavel) == 0){
                fclose(arq);
                return tmpVal;
            }
        }
    }
    return 0;
}