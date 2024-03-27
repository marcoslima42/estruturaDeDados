#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definindo a estrutura
struct conta{
    int num;
    char nome[30];
    float saldo;
}pessoa[2];
typedef struct conta Conta;

void criarConta(Conta pessoa[]){
    int flag=0;
    for(int i=0; i<2; i++){
        if(flag==0)
            printf("PRIMEIRA CONTA:\n\n");
        else 
            printf("SEGUNDA CONTA\n\n");
        printf("\nDigite seu numero de conta: \n");
        scanf("%d", &pessoa[i].num);
        printf("\nDigite seu nome: \n");
        fflush(stdin);
        gets(pessoa[i].nome);
        printf("\nDigite seu saldo: \n");
        scanf("%f", &pessoa[i].saldo);
        flag++;
        system("cls");
    }
}

int main(){
    system("cls");
    printf("BEM VINDO AO BANCO TUPINIQUIM\n");
    printf("-----------------------------\n");
    printf("Para inserir sua conta siga os passos...\n");

    criarConta(pessoa);

    
    return 0;
}