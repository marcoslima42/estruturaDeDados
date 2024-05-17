#include "lib.h"

No *criaNo(ListaD *l, int valor){
    No *novo=(No*)malloc(sizeof(No));
    novo->valor=valor;
    novo->ant=NULL;
    novo->prox=NULL;
    
    return novo;
}

void inserirFim(ListaD *l, int valor){
    No *novo=criaNo(l, valor);
    
    if(l->inicio==NULL){
        l->inicio=novo;
        l->fim=novo;
    }
    else{
        novo->ant=l->fim;
        l->fim->prox = novo;
        l->fim=novo;
    }
}

void imprimirLista(ListaD *l){
    No *aux=l->inicio;
    while(aux!=NULL){
        printf("%d ", aux->valor);
        aux=aux->prox;
    }
}
    