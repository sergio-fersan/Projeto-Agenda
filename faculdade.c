#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h"
#include "calendario.h"
#include "faculdade.h"

typedef struct{
    char materia[25];
    char professor[15];
    char tema[15];
    char grupo[7][100]; // array bidimensional, pode colocar até 7 pessoas no grupo
    int dia, mes;
} trabalho;

void criarTrabalho(){
    trabalho t;
    int num;

    FILE *arq = fopen("trabalhos.txt", "a");
    printf("Digite a materia do trabalho: ");
    fgets(t.materia, 25, stdin);
    t.materia[strcspn(t.materia, "\n")] = '\0'; // tira o \n
    fprintf(arq, "Materia: %s\n", t.materia);
    printf("Digite o nome do professor: ");
    fgets(t.professor, 15, stdin);
    t.professor[strcspn(t.professor, "\n")] = '\0';
    fprintf(arq, "Professor: %s\n", t.professor);
    printf("Digite o tema do trabalho: ");
    fgets(t.tema, 15, stdin);
    t.tema[strcspn(t.tema, "\n")] = '\0';
    fprintf(arq, "Tema: %s\n", t.tema);
    while(1){
        printf("Entre 1 e 7 pessoas, quantas tem no grupo? ");
        scanf("%d", &num);
        if(num < 1 || num > 7){
            printf("Quantidade invalida de pessoas!! Digite outro valor\n");
        } else{
            clearBuffer();
            for(int i = 1; i <= num; i++){
                printf("Digite o nome da pessoa %d: ", i);
                fgets(t.grupo[i], sizeof(t.grupo[i]), stdin);
                t.grupo[i][strcspn(t.grupo[i], "\n")] = '\0';
            }
            fprintf(arq, "Grupo: ");
            for(int j = 0; j <= num; j++){
                fprintf(arq, "%s", t.grupo[j]);
                if(j < num && j != 0){
                    fprintf(arq, ", ");
                }
            }
            fprintf(arq, "\n");
            break;
        }
    }
    printf("Digite o dia de entrega do trabalho: ");
    scanf("%d", &t.dia);
    while(1){
        printf("Digite o mes (em numero) de entrega do trabalho: ");
        scanf("%d", &t.mes);
        if(t.mes < 1 || t.mes > 12){
            printf("Data inválida!! Tente novamente\n");
        } else{
            break;
        }
    }
    clearBuffer();
    fprintf(arq, "Data: %d/%d (dd/mm)\n\n", t.dia, t.mes);
    fclose(arq);

    printf("Trabalho registrado com sucesso!!\n");
    
}