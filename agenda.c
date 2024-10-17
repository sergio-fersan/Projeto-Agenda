#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h"
#include "calendario.h"
#include "faculdade.h"

void menu();

void menuCalendario(){
    printf("-----------------------------------------------\n");
    printf("Selecione qual funcionalidade deseja utilizar:\n");
    printf("1. Criar evento\n");
    printf("2. Excluir evento\n");
    printf("3. Exibir um evento\n");
    printf("4. Exibir todos os eventos\n");
    printf("0. Sair do aplicativo\n");
    printf("-----------------------------------------------\n");
    int esc;
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
    }
}

void menuFaculdade(){
    printf("-----------------------------------------------\n");
    printf("Selecione qual funcionalidade deseja utilizar:\n");
    printf("1. Registrar trabalho/prova\n");
    printf("2. Excluir trabalho/prova\n");
    printf("3. Exibir detalhes de um trabalho/prova\n");
    printf("4. Exibir todos os trabalhos/provas\n");
    printf("0. Sair do aplicativo\n");
    printf("-----------------------------------------------\n");
    int esc;
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
    }
}

void menu(){
    printf("-----------------------------------------------\n");
    printf("Selecione qual aplicativo deseja utilizar:\n");
    printf("1. Agenda\n");
    printf("2. Planilha do banco\n");
    printf("3. Calendario\n");
    printf("4. Organizador de trabalhos de faculdade\n");
    printf("0. Sair\n");
    printf("-----------------------------------------------\n");
    int esc;
    printf("Digite sua escolha: ");
    scanf("%d", &esc);
    printf("-----------------------------------------------\n");
    switch(esc){
        case 1:
            printf("agenda");
            break;
        case 2:
            printf("planilha");
            break;
        case 3:
            menuCalendario();
            break;
        case 4:
            printf("faculdade");
            break;
        case 0:
            printf("Saindo do programa. Tchau!!!!");
            exit(0);
    }
}

void calendario(){
    printf("Aplicativo: Calendario\n");
    menuCalendario();
}

int main(){
    // IDEIA: AGENDA, PLANILHA DE BANCO, CALENDÁRIO E ORGANIZADOR DE TRABALHOS DE FACULDADE
    // PRIMEIRO TEM QUE CRIAR O ARQUIVO .BIN E AS VARIAVEIS, SÓ DEPOIS PODE ALTERAR E LER
    // DEPOIS DE CRIAR PODE APAGAR A CHAMADA DA FUNÇÃO DE CRIAR

    // AGENDA: SERVE PARA SALVAR CONTATOS E INTERAGIR
    // SALVAR CONTATO, EXLUIR CONTATO, EDITAR CONTATO, "MANDAR MENSAGEM", "LIGAR", "MANDAR E-MAIL", VER TODOS OS CONTATOS
    // CONTATO TEM: NOME COMPLETO, DESCRIÇÃO, TELEFONE, E-MAIL, ID
    // BIN

    // ORGANIZADOR DE TRABALHOS DE FACULDADE:
    // REGISTRAR TRABALHO, REGISTRAR PROVA, EXCLUIR
    // PROVA TEM: MATÉRIA, PROFESSOR, CONTEÚDO, DETALHES
    // TRABALHO TEM: MATÉRIA, PROFESSOR, TEMA, GRUPO, PRAZO
    // TXT

    // int dia, mes;
    // int diasTot = 0;
    // int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // printf("Bem vindo!!\n");
    // while(1){
    //     printf("Informe o dia atual: ");
    //     scanf("%d", &dia);
    //     printf("Informe o mes atual: ");
    //     scanf("%d", &mes);
    //     if(mes < 1 || mes > 12){
    //         printf("Data invalida!! Tente novamente\n");
    //     } else{
    //         break;
    //     }
    // }
    // if(mes != 1){
    //     for(int idx = 0; idx < (mes - 1); idx++){
    //         diasTot += diasPorMes[idx];
    //     }
    //     diasTot += dia;
    // } else{
    //     diasTot = dia;
    // }
    // printf("-----------------------------------------------\n");
    // exibirProximos(diasTot);
    // menu();


    return 0;
}