#ifndef LIB_H
#define LIB_H
#include<stdio.h>
#include<stdlib.h>

struct no{
    int valor;
    struct no *prox;
    struct no *ant;
};
typedef struct no No;

struct listaD{
    No *inicio;
    No *fim;
};
typedef struct listaD ListaD;

No *criaNo(ListaD *l, int valor);
void inserirFim(ListaD *l, int valor);
void imprimirLista(ListaD *l);

#endif