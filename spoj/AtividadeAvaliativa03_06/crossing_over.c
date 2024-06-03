#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    char valor;
    struct no *prox;
    struct no *ant;
};
typedef struct no No;

struct listaD{
    No *inicio;
    No *fim;
    int qtd;
};
typedef struct listaD ListaD;

//prototipos
No *criaNo(ListaD *l, char valor);
void inserirFim(ListaD *l, char valor);
void imprimirLista(ListaD *l);
void buscar(ListaD *l, char valor);

int main(){
    ListaD *l1=NULL;
    ListaD *l2=NULL;

    l1=(ListaD*)malloc(sizeof(ListaD));
    l1->inicio=l1->fim=NULL;
    l2=(ListaD*)malloc(sizeof(ListaD));
    l2->inicio=l2->fim=NULL;

    char vetor[100000];
    char vetor2[100000];
    char letra=' ';
    
    scanf("%s", vetor);
    scanf("%s", vetor2);
    
    //cria primeira lista
    for(int j=0; j<strlen(vetor); j++){
        letra=vetor[j];
        inserirFim(l1, letra);
    }
    //cria segunda lista
    for(int j=0; j<strlen(vetor2); j++){
        letra=vetor2[j];
        inserirFim(l2, letra);
    }
    int seq_qtd=0;
    char gene1[100000], gene2[100000];

    char vlr='a';

    buscar(l1, vlr);
    imprimirLista(l1);
    imprimirLista(l2);
    
    return 0; 
}
//fim main

No *criaNo(ListaD *l, char valor){
    No *novo=(No*)malloc(sizeof(No));
    novo->valor=valor;
    novo->ant=NULL;
    novo->prox=NULL;
    
    return novo;
}

void inserirFim(ListaD *l, char valor){
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
    No *aux=NULL;
    if(l!=NULL)
        aux=l->inicio;
    while(aux!=NULL){
        printf("%c ", aux->valor);
        aux=aux->prox;
    }
    printf("\n");

}

void buscar(ListaD *l, char valor){
    No *aux=l->inicio;

    while(aux->valor!=valor && aux->prox!=NULL)
        aux=aux->prox;
    
    printf("\n encontrei o %c", aux->valor);
}