#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct no{
    char letra;
    struct no *prox;
    struct no *ant;
};
typedef struct no No;

struct noSimples{
    char letra;
    int qtd;
    struct noSimples *prox;
};
typedef struct noSimples NoSimples;

struct listaD{
    No *inicio;
    No *fim;
    int qtd;
};
typedef struct listaD ListaD;

No *criaNo(ListaD *l, char letra);
void inserirFim(ListaD *l, char letra);
void imprimirLista(ListaD *l);
ListaD *liberarLista(ListaD *l);
NoSimples* criaNoSimples(char valorChar, int qtd);
NoSimples* insereNoFimSimples(NoSimples *l, char valorChar, int qtd);
void repetidos(ListaD *l);
void bubbleSort(ListaD *l);
void mostrarLista(NoSimples* l);
void destruirLista(NoSimples* l);

int main(){
    int qtd=0;
    char letra=' ';
    char string[100];
    ListaD* l;

    l=(ListaD*)malloc(sizeof(ListaD));
    l->inicio=NULL;
    l->fim=NULL;
    
    scanf("%d", &qtd);
    
    for(int i=0; i<qtd; i++){
        getchar();
        scanf("%s", string);
        for(int j=0; j<strlen(string); j++){
            letra=string[j];
            inserirFim(l, letra);
        }
        repetidos(l);
        
        liberarLista(l);
    }
    
    l=liberarLista(l);
    return 0;
}

void repetidos(ListaD *l){
    int qtd=0;

    NoSimples *lSimples=NULL;
    
    bubbleSort(l);

    //for(No *i=l->inicio; i!=NULL; i=i->prox){
    No *i=l->inicio;
    while(i!=NULL){
        qtd=0;
        for(No *j=l->inicio; j!=NULL; j=j->prox){
            if(i->letra==j->letra)
                qtd++;            
        }
        lSimples=insereNoFimSimples(lSimples, i->letra, qtd);
        
        for(int k=0; k<qtd; k++)
            i=i->prox;
    }
    

    mostrarLista(lSimples);
    destruirLista(lSimples);
    lSimples=NULL;
}

void mostrarLista(NoSimples* l){
    NoSimples *aux=l; 

    while(aux != NULL){
        printf("%c %d\n", aux->letra, aux->qtd);
        aux=aux->prox;
    }
}

NoSimples* criaNoSimples(char valorChar, int qtd){
    NoSimples *novo=NULL;
    novo=(NoSimples*)malloc(sizeof(NoSimples));
    novo->letra=valorChar;
    novo->prox=NULL;
    novo->qtd=qtd;
    return novo;
}

NoSimples* insereNoFimSimples(NoSimples *l, char valorChar, int qtd){
    NoSimples* aux=l;
    if(l==NULL)
        l=criaNoSimples(valorChar, qtd);
    else{
        while(aux->prox!=NULL)
            aux=aux->prox;

        aux->prox=criaNoSimples(valorChar, qtd);
        
    }
    
    return l;
}

void destruirLista(NoSimples* l){
    NoSimples *aux=l;

    while(aux!=NULL){
        l=l->prox;
        free(aux);
        aux=l;
    }
}

No *criaNo(ListaD *l, char letra){
    No *novo=(No*)malloc(sizeof(No));
    novo->letra=letra;
    novo->ant=NULL;
    novo->prox=NULL;
    
    return novo;
}

void inserirFim(ListaD *l, char letra){
    No *novo=criaNo(l, letra);
    
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
        printf("%c ", aux->letra);
        aux=aux->prox;
    }
    printf("\n");

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

    l->inicio=NULL;
    l->fim=NULL;

    return NULL;
}

void bubbleSort(ListaD *l){
    int aux=0;
    
    for(No *i=l->inicio; i!=NULL; i=i->prox)
        for(No *j=i->prox; j!=NULL; j=j->prox)
            if(i->letra>j->letra){
                aux=i->letra;
                i->letra=j->letra;
                j->letra=aux;
            }

}