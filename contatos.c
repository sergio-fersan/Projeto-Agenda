#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h"
#include "contatos.h"

typedef struct {
    char nome[30];
    char descricao[30];
    int telefone;
    char email[30];
} Contato;

void criarContato(){
    Contato ctt;
    FILE *arq = fopen("contatos.bin", "ab");
    printf("Digite o nome do contato: ");
    fgets(ctt.nome, 30, stdin);
    ctt.nome[strcspn(ctt.nome, "\n")] = '\0';
    printf("Digite a descricao do contato (pode deixar em branco): ");
    fgets(ctt.descricao, 30, stdin);
    ctt.descricao[strcspn(ctt.descricao, "\n")] = '\0';
    printf("Digite o telefone do contato: ");
    scanf("%d", &ctt.telefone);
    clearBuffer();
    printf("Digite o e-mail do contato: ");
    fgets(ctt.email, 30, stdin);
    ctt.email[strcspn(ctt.email, "\n")] = '\0';
    fwrite(&ctt, sizeof(ctt), 1, arq);
    fclose(arq);

    printf("Contato registrado com sucesso!!\n");
}

void exibirTudoContatos() {
    Contato ctt;
    FILE *arq = fopen("contatos.bin", "rb");

    printf("Contatos na sua agenda:\n");
    while (fread(&ctt, sizeof(Contato), 1, arq) == 1) {
        printf("Nome: %s\n", ctt.nome);
        printf("Descricao: %s\n", ctt.descricao);
        printf("Telefone: %d\n", ctt.telefone);
        printf("E-mail: %s\n\n", ctt.email);
    }
    fclose(arq);
}