#ifndef CALENDARIO_H
#define CALENDARIO_H

void clearBuffer();
void criarEvento();
void exibirEvento();
void excluirEvento();
void exibirTudo();
void exibirProximos(int);
void criarEventoTrabalho(const char *, int, int, int);
void excluirEventoTrabalho(const char *, int);

#endif