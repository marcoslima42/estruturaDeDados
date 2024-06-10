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
        if(auxUltimoNo1!=NULL)
            printf("\naux ultimo %c", auxUltimoNo1->valor);
        else
            printf("\naux ultimo e NULL");
    }
    
    // imprimirLista(l1);
    // imprimirLista(l2);
    
    return 0; 
}
//fim main
No *buscar(ListaD *l, char *seqPar){
    int cont=0;
    No *auxAtual=NULL;
    //percorrer a lista e encontrar a sequencia
    for(No *aux=l->inicio; aux->prox!=NULL; aux=aux->prox){
        auxAtual=aux;
        if(aux->valor == seqPar[0]){
            for(int i=0; i<strlen(seqPar); i++){
                if(aux->valor == seqPar[i]){
                    // cont++;
                    printf("\n\nigual %c", aux->valor);
                    printf("\n\nigual prox %c", aux->prox->valor);
                    printf("\n\nigual prox %c", aux->ant->valor);
                    aux=aux->prox;
                    
                }
            }
            printf("\n\nterminou loop principal");
            getch();
            
            if(cont==strlen(seqPar))
                return aux;
            else
                aux=auxAtual;
        }
        aux=aux->prox;
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
