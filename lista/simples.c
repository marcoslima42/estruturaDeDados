#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct no{
    int valor;
    struct no *prox;
};
typedef struct no No;

No* criaNo(int valor);
No* insereNoInicio(No *l, int valor);
No* insereNoFim(No *l, int valor);
void mostrarLista(No *l);
int eIgual(No* l);
No* minimum(No* l);
No* maximum(No* l);
void destruirLista(No* l);
int qtdNo(No *l);
No* reverseDuasListas(No *l);
No* removerNo(No *l, int valor);

int main(){
    No *l=NULL;
    l= criaNo(8);

    l=insereNoFim(l,4);
    l=insereNoFim(l,6);
    l=insereNoFim(l,9);

    // mostrarLista(l);
    // if(minimum(l)==NULL) printf("\nNao ha numero minimo, todos elementos da lista sao iguais");
    // else printf("\n\nmenor: %d", minimum(l)->valor);

    // if(maximum(l)==NULL) printf("\nNao ha numero maximo, todos elementos da lista sao iguais");
    // else printf("\n\nmaior: %d", maximum(l)->valor);
    
    // No *l2=NULL;
    // l2=reverseDuasListas(l);
    // printf("\n\nMostrar lista reverse\n");
    // mostrarLista(l2);
    No* aux=NULL;
    mostrarLista(l);
    aux=removerNo(l, 4);
    printf("no removido %d", aux->valor);
    free(aux);
    
    printf("\n");
    mostrarLista(l);
    destruirLista(l);
    //printf("\nLista1...");
    // destruirLista(l2);
    // printf("\nLista2...");

    
    return 0;
}

No* criaNo(int valor){
    No *novo=NULL;
    novo=(No*)malloc(sizeof(No));
    novo->valor=valor;
    novo->prox=NULL;

    return novo;
}

No* insereNoInicio(No *l, int valor){
    No* novo=NULL;
    if(l==NULL)
        l=criaNo(valor);
    else{
        novo = criaNo(valor);
        novo->prox=l;//encadeando
        l=novo;
    }
    return l;

}

No* insereNoFim(No *l, int valor){
    No* aux=l;
    if(l==NULL)
        l=criaNo(valor);
    else{
        while(aux!=NULL)
            aux=aux->prox;
        aux->prox=criaNo(valor);
    }
    
    return l;
}

void mostrarLista(No* l){
    No *aux=l; 

    while(aux != NULL){
        printf("%d ", aux->valor);
        aux=aux->prox;
    }
}

int eIgual(No* l){
    No* aux=l; 
    int num=l->valor;
    int flag=0;

    while(aux!=NULL){
        if(aux->valor == num)
            flag=1;
        else
            flag=0;
        aux=aux->prox;
    }
    
    return flag;
}

No* minimum(No* l){
    No *aux=l;
    No *menor=l; 

    while(aux!=NULL){
        if(menor->valor > aux->valor)
            menor=aux;
        aux=aux->prox;
    }

    if(eIgual(l)) menor=NULL;
    return menor;
}

No* maximum(No* l){
    No *aux=l;
    No *maior=l;

    while(aux!=NULL){
        if(maior->valor < aux->valor)
            maior=aux;
        aux=aux->prox;
    }

    if(eIgual(l)) maior=NULL;
    return maior; 
}

void destruirLista(No* l){
    No* aux=l;

    while(aux!=NULL){
        l=l->prox;
        free(aux);
        aux=l;
    }

    printf("\n\nLISTA DESTRUIDA COM SUCESSO!\n");
    mostrarLista(l);
}

int qtdNo(No *l){
    int qtd=0;
    No *aux=l;
    while(aux!=NULL){
        qtd++;
        aux=aux->prox;
    }
    return qtd; 
}

No* reverseDuasListas(No *l){
    No *aux=l;
    No *l2=NULL;

    while(aux!=NULL){
        l2=insereNoInicio(l2, aux->valor);
        aux=aux->prox;
    }

    return l2;
}

No* removerNo(No *l, int valor){
    No* aux=l;
    No* anterior=NULL;
    while(aux->valor!=valor){
        anterior=aux;
        aux=aux->prox;
    }

    anterior->prox=aux->prox;
    aux->prox=NULL;       
    
    return aux;
}