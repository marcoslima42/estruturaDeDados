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
ListaD *criarLista();
void inputLista(ListaD *l);
No *buscar(ListaD *l, char *seqPar);
void adicionar(ListaD *l, No *auxUltimoNo, char *seqPar);
void remover(ListaD *l, No *auxUltimoNo, int tam);
void inputListaPar(ListaD *l, char *vetor);

int main(){
    ListaD *l1=criarLista(), *l2=criarLista();
    char seqPar1[1000], seqPar2[1000];
    int qtdPares=0;
    No *auxUltimoNo1=NULL, *auxUltimoNo2=NULL;

    inputLista(l1);
    inputLista(l2);
    scanf("%d", &qtdPares);

    for(int i=0; i<qtdPares; i++){
        //entrando com a sequencia de pares, vetores de char
        scanf("%s", seqPar1);
        scanf("%s", seqPar2);
        auxUltimoNo1=buscar(l1, seqPar1);
        adicionar(l1, auxUltimoNo1, seqPar2);

        printf("\n");
        imprimirLista(l1);
        printf("\n");
        imprimirLista(l2);
        //remover
        // printf("o ultimo foi '%c' ", auxUltimoNo1->prox->valor);

    }
    
    // imprimirLista(l1);
    // imprimirLista(l2);
    
    return 0; 
}
//fim main

void adicionar(ListaD *l, No *auxUltimoNo, char *seqPar){
    ListaD *listaSeqPar=criarLista();

    inputListaPar(listaSeqPar, seqPar);

    //add no fim
    if(auxUltimoNo->prox==NULL){
        auxUltimoNo->prox=listaSeqPar->inicio;
        listaSeqPar->inicio->ant=auxUltimoNo;
        l->fim=listaSeqPar->fim;
    }
    //add no meio
    else if(auxUltimoNo->prox != NULL && auxUltimoNo->ant != NULL){
        auxUltimoNo->prox->ant=listaSeqPar->fim;
        listaSeqPar->inicio->ant=auxUltimoNo;
        listaSeqPar->fim->prox=auxUltimoNo->prox;
        auxUltimoNo->prox=listaSeqPar->inicio;
    }
    //add no inicio
    else if(auxUltimoNo->ant == NULL && auxUltimoNo->prox != NULL){
        auxUltimoNo->ant=listaSeqPar->fim;
        listaSeqPar->fim->prox=auxUltimoNo;
        l->inicio=listaSeqPar->inicio;
    }
    int tam=strlen(seqPar);
    //Em c dentro de uma chamada de função posso chamar outra função?
    remover(l, auxUltimoNo, tam);

    listaSeqPar=NULL;
}

void remover(ListaD *l, No *auxUltimoNo, int tam){
    No *aux=auxUltimoNo, *auxNavegar;
    //se o que for removido esta no inicio
    if(auxUltimoNo->ant == NULL){
        auxUltimoNo->prox->ant=NULL;
        
        for(int i=tam; i>=1; i--){
            if(auxUltimoNo->ant != NULL){
                aux=auxUltimoNo;
                auxUltimoNo=auxUltimoNo->ant;
            }
            free(aux);
        }
    }//se o que for removido esta no meio da lista
    else{ 
        for(int i=tam; i>=1; i--)
            aux=aux->ant;
    
        auxUltimoNo->prox->ant=aux;
        aux->prox=auxUltimoNo->prox;

        for(int i=tam; i>=1; i--){
            if(auxUltimoNo->ant != NULL){
                aux=auxUltimoNo;
                auxUltimoNo=auxUltimoNo->ant;
            }
            free(aux);
        }
    }

}

No *buscar(ListaD *l, char *seqPar){
    int cont=0;
    No *auxAtual=NULL;
    //percorrer a lista e encontrar a sequencia
    for(No *aux=l->inicio; aux->prox!=NULL; aux=aux->prox){
        //encontrar a primeira letra igual
        auxAtual=aux;
        if(aux->valor==seqPar[0]){
            for(int i=0; i<strlen(seqPar); i++){
                if(aux->valor==seqPar[i]){
                    cont++;
                }
                aux=aux->prox;
            }
        }

        if(cont==strlen(seqPar)){
            printf("ENCONTROU!");
            return aux->ant;
        }
        aux=auxAtual;
    }
    return NULL;
}
void inputLista(ListaD *l){
    char vetor[1000];
    char letra=' ';
    
    scanf("%s", vetor);

    for(int i=0; i<strlen(vetor); i++){
        letra=vetor[i];
        inserirFim(l, letra);
    }
}

void inputListaPar(ListaD *l, char *vetor){
    char letra=' ';
    
    for(int i=0; i<strlen(vetor); i++){
        letra=vetor[i];
        inserirFim(l, letra);
    }
}

ListaD *criarLista(){
    ListaD *l=(ListaD*)malloc(sizeof(ListaD));
    l->inicio=l->fim=NULL;
}

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
