#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendario.h"
#include "faculdade.h"
#include "contatos.h"

void menu();

void menuCalendario(){
    int esc;
    do{
        printf("-----------------------------------------------\n");
        printf("Selecione qual funcionalidade deseja utilizar:\n");
        printf("1. Criar evento\n");
        printf("2. Excluir evento\n");
        printf("3. Exibir um evento\n");
        printf("4. Exibir todos os eventos\n");
        printf("0. Sair do aplicativo\n");
        printf("-----------------------------------------------\n");
        printf("Digite sua escolha: ");
        scanf("%d", &esc);
        printf("-----------------------------------------------\n");
        clearBuffer();
        switch(esc){
            case 1:
                criarEvento();
                menuCalendario();
                break;
            case 2:
                excluirEvento();
                menuCalendario();
                break;
            case 3:
                exibirEvento();
                menuCalendario();
                break;
            case 4:
                exibirTudo();
                menuCalendario();
                break;
            case 0:
                menu();
                break;
            default:
                printf("Opcao invalida!! Tente novamente\n");
        }
    } while(esc != 0);
}

void menuFaculdade(){
    int esc;
    do{
        printf("-----------------------------------------------\n");
        printf("Selecione qual funcionalidade deseja utilizar:\n");
        printf("1. Registrar trabalho/prova\n");
        printf("2. Excluir trabalho/prova\n");
        printf("3. Exibir detalhes de um trabalho/prova\n");
        printf("4. Exibir todos os trabalhos/provas\n");
        printf("0. Sair do aplicativo\n");
        printf("-----------------------------------------------\n");
        printf("Digite sua escolha: ");
        scanf("%d", &esc);
        printf("-----------------------------------------------\n");
        clearBuffer();
        switch(esc){
            case 1:
                criarTrabalho();
                menuFaculdade();
                break;
            case 2:
                excluirTrabalho();
                menuFaculdade();
                break;
            case 3:
                exibirTrabalho();
                menuFaculdade();
                break;
            case 4:
                exibirTudoTrabalho();
                menuFaculdade();
                break;
            case 0:
                menu();
                break;
            default:
                printf("Opcao invalida!! Tente novamente\n");
        }
    } while(esc != 0);
}

void menuAgenda(){
    int esc;
    do{
        printf("-----------------------------------------------\n");
        printf("Selecione qual funcionalidade deseja utilizar:\n");
        printf("1. Criar contato\n");
        printf("2. Excluir contato\n");
        printf("3. Exibir um contato\n");
        printf("4. Exibir todos os contatos\n");
        printf("0. Sair do aplicativo\n");
        printf("-----------------------------------------------\n");
        printf("Digite sua escolha: ");
        scanf("%d", &esc);
        printf("-----------------------------------------------\n");
        clearBuffer();
        switch(esc){
            case 1:
                criarContato();
                menuAgenda();
                break;
            case 2:
                excluirContato();
                menuAgenda();
                break;
            case 3:
                exibirContato();
                menuAgenda();
                break;
            case 4:
                exibirTudoContatos();
                menuAgenda();
                break;
            case 0:
                menu();
                break;
            default:
                printf("Opcao invalida!! Tente novamente\n");
        }
    } while(esc != 0);
}

void menu(){
    int esc;
    do{
        printf("-----------------------------------------------\n");
        printf("Selecione qual aplicativo deseja utilizar:\n");
        printf("1. Agenda\n");
        printf("2. Calendario\n");
        printf("3. Organizador de trabalhos de faculdade\n");
        printf("0. Sair\n");
        printf("-----------------------------------------------\n");
        printf("Digite sua escolha: ");
        scanf("%d", &esc);
        switch(esc){
            case 1:
                menuAgenda();
                break;
            case 2:
                menuCalendario();
                break;
            case 3:
                menuFaculdade();
                break;
            case 0:
                printf("Saindo do programa. Tchau!!!!");
                exit(0);
            default:
                printf("Opcao invalida!! Tente novamente\n");
        }
    } while(esc != 0);
}

void calendario(){
    printf("Aplicativo: Calendario\n");
    menuCalendario();
}

int main(){
    

    int dia, mes;
    int diasTot = 0;
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Bem vindo!!\n");
    while(1){
        printf("Informe o dia atual: ");
        scanf("%d", &dia);
        printf("Informe o mes atual: ");
        scanf("%d", &mes);
        if(mes < 1 || mes > 12){
            printf("Data invalida!! Tente novamente\n");
        } else{
            break;
        }
    }
    if(mes != 1){
        for(int idx = 0; idx < (mes - 1); idx++){
            diasTot += diasPorMes[idx];
        }
        diasTot += dia;
    } else{
        diasTot = dia;
    }
    printf("-----------------------------------------------\n");
    exibirProximos(diasTot);
    menu();

    
    

    return 0;
}