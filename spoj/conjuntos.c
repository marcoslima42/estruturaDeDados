#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct no{
    int valor;
    struct no *prox;
};
typedef struct no No;


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

void mostrarLista(No *l){
    No *aux=l; 

    while(aux != NULL){
        printf("%d ", aux->valor);
        aux=aux->prox;
        //getch();
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

No* entrada(No* l, int valor){
    int input=0;
    
    for(int i=0; i<valor; i++){
        scanf("%d",&input);
        l=insereNoInicio(l, input);
    }
    return l;
}

No* insereFim(No* l, int valor){
    No* novo = criaNo(valor);
    No *aux=l;
    
    if(l==NULL){
        l=novo;
    }
    else{
        while(aux->prox!=NULL)
            aux=aux->prox;
            
        aux->prox=novo;
    }
    return l;
}

void imprimirIntersecao(No *l, No *l2){
    No *lInversa=NULL;
    No *l2Inversa=NULL;

    lInversa=reverseDuasListas(l);
    l2Inversa=reverseDuasListas(l2);

    No *aux=lInversa;
    No *aux2=l2Inversa;
    //interseccao
    for(aux=lInversa; aux!=NULL; aux=aux->prox){
        for(aux2=l2Inversa; aux2!=NULL; aux2=aux2->prox){
            if(aux->valor==aux2->valor){
                printf("%d ", aux->valor);
            }
        }
    }
    //uniao
    aux=lInversa;
    aux2=l2Inversa;
    
    printf("\n");
    No *uniao=NULL;
    while(aux!=NULL && aux2!=NULL){
            if(aux->valor<aux2->valor){
                uniao=insereFim(uniao, aux->valor);
                aux=aux->prox;
            }
            else if(aux->valor==aux2->valor){
                uniao=insereFim(uniao, aux->valor);
                aux=aux->prox;
                aux2=aux2->prox;
            }
            else if(aux->valor>aux2->valor){
                uniao=insereFim(uniao, aux2->valor);
                aux2=aux2->prox;
            }   
    }
    //caso a primeira lista nao tenha finalizado
    while(aux!=NULL){
        uniao=insereFim(uniao, aux->valor);
        aux=aux->prox;
    }
    //caso a segunda lista nao tenha finalizado
    while(aux2!=NULL){
        uniao=insereFim(uniao, aux2->valor);
        aux2=aux2->prox;
    }
    mostrarLista(uniao);


}
int main(){
    int n=0, m=0;
    No *l=NULL, *l2=NULL;

    scanf("%d %d", &n, &m);

    l=entrada(l, n);
    l2=entrada(l2, m);

    imprimirIntersecao(l, l2);
    
    return 0;
}