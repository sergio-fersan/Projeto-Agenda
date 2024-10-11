#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30];
    int dia, mes;
    char local[30];
    char horario[8];
} evento;

void criarEvento(){
    evento evt;
    printf("Digite o titulo do evento: ");
    fgets(evt.nome, 30, stdin);
    evt.nome[strcspn(evt.nome, "\n")] = '\0'; // tira o \n
    printf("Digite o dia do evento: ");
    scanf("%d", &evt.dia);
    printf("Digite o mes (em numero) do evento: ");
    scanf("%d", &evt.mes);
    clearBuffer();
    printf("Digite o local do evento (digite 0 se nao houver local): ");
    fgets(evt.local, 30, stdin);
    evt.local[strcspn(evt.local, "\n")] = '\0';
    if(strlen(evt.local) == 0){
        evt.local == '\0';
    }
    printf("Digite o horario do evento (digite 0 se nao houver horario): ");
    fgets(evt.horario, 8, stdin);
    evt.horario[strcspn(evt.horario, "\n")] = '\0';
    if(strlen(evt.horario) == 0){
        evt.horario == '\0';
    }
    printf("Nome: %s, dia: %d, mes: %d, local: %s, horario: %s\n", evt.nome, evt.dia, evt.mes, evt.local, evt.horario);
}