#include <stdio.h>
#include <stdlib.h> 

struct no{
    int valor;
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

No *criaNo(ListaD *l, int valor);
void inserirFim(ListaD *l, int valor);
void imprimirLista(ListaD *l);
ListaD *liberarLista(ListaD *l);
void reverse(ListaD *l, int qtd);


int main(){
    int qtd=0, valor=0;
    ListaD* l;
    l=(ListaD*)malloc(sizeof(ListaD));
    l->inicio=NULL;
    l->fim=NULL;
    
    scanf("%d", &qtd);

    for(int i=0; i<qtd; i++){
        scanf("%d", &valor);
        inserirFim(l, valor);
    }

    reverse(l, qtd);
    
    l=liberarLista(l);
    return 0;
}

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
    No *aux=NULL;
    if(l!=NULL)
        aux=l->inicio;
    while(aux!=NULL){
        printf("%d ", aux->valor);
        aux=aux->prox;
    }
    printf("\n");

}

void reverse(ListaD *l, int qtd){
    No* aux1=l->inicio;
    No* aux2=l->fim;
    int auxInteiro=0;

    for(int i=0; i<((qtd-(qtd%2))/2); i++){
        //invertendo
        auxInteiro=aux1->valor;
        aux1->valor=aux2->valor;
        aux2->valor=auxInteiro;
        //navegando
        aux1=aux1->prox;
        aux2=aux2->ant;
    }

    imprimirLista(l);
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

    free(l);
    return NULL;
}