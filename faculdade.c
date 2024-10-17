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

typedef struct{
    char materia[25];
    char professor[15];
    char conteudo[50];
    char detalhes[50];
    int dia, mes;
} prova;

void criarTrabalho(){
    int esc;
    while(1){
        printf("Digite 1 para trabalho e 2 para prova: ");
        scanf("%d", &esc);
        if(esc != 1 && esc != 2){
            printf("Valor invalido!! Tente novamente\n");
        } else if(esc == 1){
            trabalho t;
            int num;

            clearBuffer();
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
            fprintf(arq, "Prazo: %d/%d (dd/mm)\n\n", t.dia, t.mes);
            fclose(arq);

            criarEventoTrabalho(t.materia, t.dia, t.mes, 1);
            printf("Trabalho registrado com sucesso!!\n");
            break;
        } else{
            prova p;

            clearBuffer();
            FILE *arq = fopen("provas.txt", "a");
            printf("Digite a materia da prova: ");
            fgets(p.materia, 25, stdin);
            p.materia[strcspn(p.materia, "\n")] = '\0';
            fprintf(arq, "Materia: %s\n", p.materia);
            printf("Digite o nome do professor: ");
            fgets(p.professor, 15, stdin);
            p.professor[strcspn(p.professor, "\n")] = '\0';
            fprintf(arq, "Professor: %s\n", p.professor);
            printf("Digite o conteudo da prova: ");
            fgets(p.conteudo, 50, stdin);
            p.conteudo[strcspn(p.conteudo, "\n")] = '\0';
            fprintf(arq, "Conteudo: %s\n", p.conteudo);
            printf("Digite detalhes da prova (se eh em dupla, com consulta etc.): ");
            fgets(p.detalhes, 50, stdin);
            p.detalhes[strcspn(p.detalhes, "\n")] = '\0';
            fprintf(arq, "Detalhes: %s\n", p.detalhes);
            printf("Digite o dia da prova: ");
            scanf("%d", &p.dia);
            while(1){
                printf("Digite o mes (em numero) da prova: ");
                scanf("%d", &p.mes);
                if(p.mes < 1 || p.mes > 12){
                    printf("Data inválida!! Tente novamente\n");
                } else{
                    break;
                }
            }
            clearBuffer();
            fprintf(arq, "Data: %d/%d (dd/mm)\n\n", p.dia, p.mes);
            fclose(arq);

            criarEventoTrabalho(p.materia, p.dia, p.mes, 2);
            printf("Prova registrada com sucesso!!\n");
            break;
        }
    }
    
}

void excluirTrabalho(){
    int achou = 0;
    char tmp[30];
    int esc;
    while(1){
        printf("Digite 1 para excluir um trabalho, 2 para excluir uma prova e 0 para sair: ");
        scanf("%d", &esc);
        clearBuffer();
        if(esc != 1 && esc != 2 && esc != 0){
            printf("Valor invalido!! Tente novamente\n");
        } else if(esc == 0){
            return;
        } else if(esc == 1){
            trabalho t;
            while(1){
                printf("Digite a materia do trabalho a ser excluido (digite 0 para sair): ");
                fgets(tmp, 30, stdin);
                tmp[strcspn(tmp, "\n")] = '\0';
                if(strcmp(tmp, "0") == 0){
                    return;
                }
                FILE *arq = fopen("trabalhos.txt", "r");
                FILE *arqTmp = fopen("tmp.txt", "w");
                while(fscanf(arq, "Materia: %[^\n]\n", t.materia) == 1){
                    fscanf(arq, "Professor: %[^\n]\n", t.professor);
                    fscanf(arq, "Tema: %[^\n]\n", t.tema);
                    fscanf(arq, "Grupo: %[^\n]\n", t.grupo);
                    fscanf(arq, "Prazo: %d/%d (dd/mm)\n\n", &t.dia, &t.mes);
                    if(strcmp(t.materia, tmp) != 0){
                        fprintf(arqTmp, "Materia: %s\n", t.materia);
                        fprintf(arqTmp, "Professor: %[^\n]\n", t.professor);
                        fprintf(arqTmp, "Tema: %[^\n]\n", t.tema);
                        fprintf(arqTmp, "Grupo: %[^\n]\n", t.grupo);
                        fprintf(arqTmp, "Prazo: %d/%d (dd/mm)\n\n", &t.dia, &t.mes);
                    } else{
                        achou = 1;
                    }
                }
                fclose(arq);
                fclose(arqTmp);
                if(achou != 1){
                    printf("Trabalho nao encontrado!! Tente novamente\n");
                    remove("tmp.txt");
                } else{
                    remove("trabalhos.txt");
                    rename("tmp.txt", "trabalhos.txt");
                    excluirEventoTrabalho(t.materia, 1);
                    printf("Trabalho removido com sucesso!!\n");
                    break;
                }
            }

        } else{
            prova p;
            while(1){
                printf("Digite a materia da prova a ser excluida (digite 0 para sair): ");
                fgets(tmp, 30, stdin);
                tmp[strcspn(tmp, "\n")] = '\0';
                if(strcmp(tmp, "0") == 0){
                    return;
                }
                FILE *arq = fopen("provas.txt", "r");
                FILE *arqTmp = fopen("tmp.txt", "w");
                while(fscanf(arq, "Materia: %[^\n]\n", p.materia) == 1){
                    fscanf(arq, "Professor: %[^\n]\n", p.professor);
                    fscanf(arq, "Conteudo: %[^\n]\n", p.conteudo);
                    fscanf(arq, "Detalhes: %[^\n]\n", p.detalhes);
                    fscanf(arq, "Data: %d/%d (dd/mm)\n\n", &p.dia, &p.mes);
                    if(strcmp(p.materia, tmp) != 0){
                        fprintf(arqTmp, "Materia: %s\n", p.materia);
                        fprintf(arqTmp, "Professor: %s\n", p.professor);
                        fprintf(arqTmp, "Conteudo: %s\n", p.conteudo);
                        fprintf(arqTmp, "Detalhes: %s\n", p.detalhes);
                        fprintf(arqTmp, "Data: %d/%d (dd/mm)\n\n", p.dia, p.mes);
                    } else {
                        achou = 1;
                    }
                }
                fclose(arq);
                fclose(arqTmp);
                if(achou != 1){
                    printf("Prova nao encontrada!! Tente novamente\n");
                    remove("tmp.txt");
                } else{
                    remove("provas.txt");
                    rename("tmp.txt", "provas.txt");
                    excluirEventoTrabalho(p.materia, 2);
                    printf("Prova removida com sucesso!!\n");
                    break;
                }
            }

        }
        break;
    }
}

void exibirTrabalho(){
    int achou = 0;
    int tipo;
    char tmp[25];
    while(1){
        printf("Digite 1 para trabalho e 2 para prova (digite 0 para sair): ");
        scanf("%d", &tipo);
        clearBuffer();
        if(tipo == 0){
            return;
        } else if(tipo == 1){
            trabalho t;
            while(1){
                printf("Digite a materia do trabalho: ");
                fgets(tmp, 25, stdin);
                tmp[strcspn(tmp, "\n")] = '\0';
                FILE *arq = fopen("trabalhos.txt", "r");
                while(fscanf(arq, "Materia: %[^\n]\n", t.materia) == 1){
                    fscanf(arq, "Professor: %[^\n]\n", t.professor);
                    fscanf(arq, "Tema: %[^\n]\n", t.tema);
                    fscanf(arq, "Grupo: %[^\n]\n", t.grupo);
                    fscanf(arq, "Prazo: %d/%d (dd/mm)\n\n", &t.dia, &t.mes);
                    if(strcmp(t.materia, tmp) == 0){
                        printf("Trabalho encontrado:\n");
                        printf("Materia: %s\n", t.materia);
                        printf("Professor: %s\n", t.professor);
                        printf("Tema: %s\n", t.tema);
                        printf("Grupo: %s\n", t.grupo);
                        printf("Prazo: %02d/%02d (dd/mm)\n", t.dia, t.mes);
                        achou = 1;
                        break;
                    }
                }
                if(achou != 1){
                    printf("Trabalho nao encontrado!! Tente novamente\n");
                } else{
                    break;
                }
                fclose(arq);
            }
        } else{
            prova p;
            while(1){
                printf("Digite a materia da prova: ");
                fgets(tmp, 25, stdin);
                tmp[strcspn(tmp, "\n")] = '\0';
                FILE *arq = fopen("provas.txt", "r");
                while(fscanf(arq, "Materia: %[^\n]\n", p.materia) == 1){
                    fscanf(arq, "Professor: %[^\n]\n", p.professor);
                    fscanf(arq, "Conteudo: %[^\n]\n", p.conteudo);
                    fscanf(arq, "Detalhes: %[^\n]\n", p.detalhes);
                    fscanf(arq, "Data: %d/%d (dd/mm)\n\n", &p.dia, &p.mes);
                    if(strcmp(p.materia, tmp) == 0){
                        printf("Prova encontrada:\n");
                        printf("Materia: %s\n", p.materia);
                        printf("Professor: %s\n", p.professor);
                        printf("Conteudo: %s\n", p.conteudo);
                        printf("Detalhes: %s\n", p.detalhes);
                        printf("Data: %02d/%02d (dd/mm)\n", p.dia, p.mes);
                        achou = 1;
                        break;
                    }
                }
                if(achou != 1){
                    printf("Prova nao encontrada!! Tente novamente\n");
                } else{
                    break;
                }
                fclose(arq);
            }
        }
        break;
    }
}

void exibirTudoTrabalho(){
    char linha[100];
    FILE *arq = fopen("trabalhos.txt", "r");

    printf("Lista de trabalhos:\n");
    while(fgets(linha, sizeof(linha), arq) != NULL){
        printf("%s", linha);
    }
    fclose(arq);

    FILE *arq2 = fopen("provas.txt", "r");

    printf("Lista de provas:\n");
    while(fgets(linha, sizeof(linha), arq) != NULL){
        printf("%s", linha);
    }
    fclose(arq2);

    
}