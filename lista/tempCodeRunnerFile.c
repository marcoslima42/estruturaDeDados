
#include <stdio.h>
#include <stdlib.h>

struct no {

int valor;

struct no *prox;

};
typedef struct no No;

No* cria_no(int num)
{
    No* espaco = (No*)malloc(sizeof(No));


    espaco->valor = num;
    espaco->prox = NULL;

    return espaco;

}

No* insere_no(No* ponteiro)
{
    int num = 0;
    scanf("%d", &num);

    No* novo = cria_no(num);

    if(ponteiro == NULL || num <= ponteiro->valor)
    {
        novo->prox = ponteiro;
        ponteiro = novo;

    } else {

    No* pot = ponteiro;

    while(pot->prox != NULL && pot->prox->valor < num)
    {
        pot = pot->prox;
    }

    novo->prox = pot->prox;
    pot->prox = novo;

    }

return ponteiro;
}



No* cria_node(int nume)
{
    No* espaco = (No*)malloc(sizeof(No));




    espaco->valor = nume;
    espaco->prox = NULL;

    return espaco;

}

No* insere_node(No* ponteiro2, No* ponteiro)
{
    int nume = 0;
    scanf("%d", &nume);


    No* novo = cria_no(nume);
    No* aux2 = ponteiro;
    
    

    if(ponteiro2 == NULL)
    {
        ponteiro2 = aux2;

    }else if (ponteiro2 == NULL)
    {
        ponteiro2 = novo;
    }

    if(nume <= ponteiro2->valor)
    {
        novo->prox = ponteiro2;
        ponteiro2 = novo;

    } else {

    No* pot = ponteiro2;

    while(pot->prox != NULL && pot->prox->valor < nume)
    {
        pot = pot->prox;
    }

    novo->prox = pot->prox;
    pot->prox = novo;

    }

return ponteiro2;
}


 void mostrarintercecao(No* ponteiro2)
 {

int nume;

     No* aux = ponteiro2;

int fat;


     nume;

     while(aux != NULL)
     {

             if(aux->valor == nume && fat != nume)
             {
                 
                 printf("%d ", aux->valor);
                 
                  fat = aux->valor;
                  nume = aux->valor;
                  aux = aux->prox;

             }  else  {

               nume = aux->valor;
               aux = aux->prox;
         
             }


     }

printf(" \n");

 }
 
 void mostraruniao(No* ponteiro2)
 {

int nume;

     No* aux = ponteiro2;

     nume = aux->valor;
     
     printf("%d ", aux->valor);

     while(aux != NULL)
     {

             if(aux->valor == nume)
             {
                 nume = aux->valor;
                aux = aux->prox;

             } else {

               printf("%d ", aux->valor);

              nume = aux->valor;
               aux = aux->prox;
             }

     }

printf(" \n");

 }
int main()
{

    No* ponteiro = NULL;

    int num, nume, i;
    int cont = 0;


    nume = num = 0;

    scanf("%d %d", &num, &nume);
    
    
    if(num != 0)
    {
    for(i = 0; i < num; i++)
    {
    
    ponteiro = insere_no(ponteiro);

    }
    }else{
        printf("\n");
        
    }


   
No* ponteiro2 = NULL;

    if(nume != 0){
        
    for(i = 0; i < nume; i++)
    {

    ponteiro2 = insere_node(ponteiro2, ponteiro);

    }
    } else {
        
        printf("\n");
        
    }
    
if (num != 0 && nume != 0)
{
 
 printf(" \n");
 
 mostraruniao(ponteiro2);
 
} else {

    mostrarintercecao(ponteiro2);
    mostraruniao(ponteiro2);
}
 


    return 0;
}
