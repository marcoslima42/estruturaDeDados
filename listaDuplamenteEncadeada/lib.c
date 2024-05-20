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

void inserirInicio(ListaD *l, int valor){
    No *novo=criaNo(l, valor);
    
    if(l->inicio==NULL){
        l->inicio=novo;
        l->fim=novo;
    }
    else 
    {
        l->inicio->ant=novo;
        novo->prox=l->inicio;
        l->inicio=novo;
    }
}

No *buscar(ListaD *l, int valor){
    No *aux=l->inicio;

    while(aux->valor!=valor && aux->prox!=NULL)
        aux=aux->prox;
    
    return aux;
}

void inserirMeio(ListaD *l, int valorInserir, int valorBuscar){
    No *novo=criaNo(l, valorInserir);
    No *aux=buscar(l, valorBuscar);
    
    //encadeando a direita do no novo
    novo->prox=aux->prox;
    aux->prox->ant=novo;
    //encadeando a esquerda do no novo
    novo->ant=aux;
    aux->prox=novo;
}

No *removerNo(ListaD *l, int valor){
    No *aux=buscar(l,valor);
    
    //remover meio
    if(aux->prox!=NULL && aux->ant!=NULL){
        aux->ant->prox=aux->prox;
        aux->prox->ant=aux->ant;
    }
    //remover fim
    else if(aux==l->fim){
        l->fim=aux->ant;
        aux->ant->prox=NULL;
    }
    //remover no inicio
    else{
        l->inicio=aux->prox;
        aux->prox->ant=NULL;
    }

    aux->prox=aux->ant=NULL; 
    return aux;
}

void imprimirLista(ListaD *l){
    No *aux=NULL;
    if(l!=NULL)
        aux=l->inicio;
    while(aux!=NULL){
        printf("%d ", aux->valor);
        aux=aux->prox;
    }
}

ListaD* liberarLista(ListaD *l){
    No *aux=l->inicio;
    int qtd=0; 

    while(aux!=NULL){
        l->inicio=aux->prox;
        free(aux);
        aux=l->inicio;
        qtd++;
    }
    printf("\n\nlista destruida %d", qtd);

    return NULL;
}

