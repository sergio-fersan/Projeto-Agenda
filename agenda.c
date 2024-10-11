#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variaveis.h"

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
    switch(esc){
        case 1:
            printf("agenda");
        case 2:
            printf("planilha");
        case 3:
            printf("calendario");
        case 4:
            printf("faculdade");
        case 0:
            printf("Saindo do programa. Tchau!!!!");
            exit(0);
    }
}

int main(){
    // IDEIA: AGENDA, PLANILHA DE BANCO, CALENDÁRIO E ORGANIZADOR DE TRABALHOS DE FACULDADE
    // PRIMEIRO TEM QUE CRIAR O ARQUIVO .BIN E AS VARIAVEIS, SÓ DEPOIS PODE ALTERAR E LER
    // DEPOIS DE CRIAR PODE APAGAR A CHAMADA DA FUNÇÃO DE CRIAR

    // AGENDA: SERVE PARA SALVAR CONTATOS E INTERAGIR
    // SALVAR CONTATO, EXLUIR CONTATO, EDITAR CONTATO, "MANDAR MENSAGEM", "LIGAR", "MANDAR E-MAIL", VER TODOS OS CONTATOS
    // CONTATO TEM: NOME COMPLETO, DESCRIÇÃO, TELEFONE, E-MAIL, ID
    
    // PLANILHA DE BANCO: SERVE PARA ORGANIZAR GASTOS DO BANCO
    // REGISTRAR SALDO, REGISTRAR DEPÓSITO, REGISTRAR COMPRA PARCELADA
    // REGISTRO TEM: DATA, OPERAÇÃO, VALOR

    // CALENDÁRIO: SERVE PARA ORGANIZAR EVENTOS E LEMBRAR O USUÁRIO
    // LEMBRA OO USUÁRIO DE EVENTOS PRÓXIMOS TODA VEZ QUE ENTRAR
    // MARCAR EVENTO, EXCLUIR EVENTO
    // EVENTO TEM: NOME, DATA, LOCAL, HORÁRIO, PRAZO

    // ORGANIZADOR DE TRABALHOS DE FACULDADE:
    // REGISTRAR TRABALHO, REGISTRAR PROVA, EXCLUIR
    // PROVA TEM: MATÉRIA, PROFESSOR, CONTEÚDO, DETALHES
    // TRABALHO TEM: MATÉRIA, PROFESSOR, TEMA, GRUPO, PRAZO
    printf("Bem vindo!!\n");
    menu();

    return 0;
}