#include <stdio.h>
#include <string.h>
#include "calendario.h"
#include "variaveis.h"

typedef struct{
    char nome[30];
    int dia, mes;
    char local[30];
    char horario[8];
} evento;

void criarEvento(){
    evento evt;

    FILE *arq = fopen("eventos.txt", "a");
    printf("Digite o titulo do evento: ");
    fgets(evt.nome, 30, stdin);
    evt.nome[strcspn(evt.nome, "\n")] = '\0'; // tira o \n
    fprintf(arq, "Nome: %s\n", evt.nome);
    printf("Digite o dia do evento: ");
    scanf("%d", &evt.dia);
    printf("Digite o mes (em numero) do evento: ");
    scanf("%d", &evt.mes);
    clearBuffer();
    fprintf(arq, "Data: %d/%d (dd/mm)\n", evt.dia, evt.mes);
    printf("Digite o local do evento (deixe em branco se nao houver local): ");
    fgets(evt.local, 30, stdin);
    evt.local[strcspn(evt.local, "\n")] = '\0';
    if(strlen(evt.local) == 0){ // verifica se ta em branco
        evt.local == '\0';
        fprintf(arq, "Local: 0\n");
    } else{
        fprintf(arq, "Local: %s\n", evt.local);
    }
    printf("Digite o horario do evento (deixe em branco se nao houver horario): ");
    fgets(evt.horario, 8, stdin);
    evt.horario[strcspn(evt.horario, "\n")] = '\0';
    if(strlen(evt.horario) == 0){
        evt.horario == '\0';
        fprintf(arq, "Horario: 0\n\n");
    } else{
        fprintf(arq, "Horario: %s\n\n", evt.horario);
    }
    fclose(arq);

    printf("Evento registrado com sucesso!!\n");
}

void exibirEvento(){
    int achou = 0;
    char tmp[30];
    evento evtTmp;
    while(1){
        printf("Digite o nome do evento (digite 0 para sair): ");
        fgets(tmp, 30, stdin);
        tmp[strcspn(tmp, "\n")] = '\0';
        if(strcmp(tmp, "0") == 0){
            return;
        }
        FILE *arq = fopen("eventos.txt", "r");
        while(fscanf(arq, "Nome: %[^\n]\n", evtTmp.nome) == 1){
            fscanf(arq, "Data: %d/%d (dd/mm)\n", &evtTmp.dia, &evtTmp.mes);
            fscanf(arq, "Local: %[^\n]\n", evtTmp.local);
            fscanf(arq, "Horario: %[^\n]\n\n", evtTmp.horario);
            if(strcmp(evtTmp.nome, tmp) == 0){
                printf("Evento encontrado:\n");
                printf("Nome: %s\n", evtTmp.nome);
                printf("Data: %02d/%02d (dd/mm)\n", evtTmp.dia, evtTmp.mes);
                printf("Local: %s\n", evtTmp.local);
                printf("Horario: %s\n", evtTmp.horario);
                achou = 1;
                break;
            }
        }
        if(achou != 1){
            printf("Evento nao encontrado!! Tente novamente\n");
        } else{
            break;
        }
        fclose(arq);
    }
}