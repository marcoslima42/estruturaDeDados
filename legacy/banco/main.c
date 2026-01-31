#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//definindo a estrutura
struct conta{
    int num;
    char nome[30];
    float saldo;
}pessoa[2];
typedef struct conta Conta;

void mostrarConta(Conta pessoa[]){
    int flag=0;
    for(int i=0; i<2; i++){
        if(flag==0)
            printf("PRIMEIRA CONTA:\n\n");
        else 
            printf("SEGUNDA CONTA\n\n");
        printf("\nNome: \n");
        printf("%s", pessoa[i].nome);
        printf("\nNumero de conta: \n");
        printf("\n%d", pessoa[i].num);
        printf("\nSeu saldo: \n");
        printf("\n%.2f", pessoa[i].saldo);
        flag++;
        printf("\n\nDIGITE ENTER PARA SAIR");
        getch();
        if(flag!=0)
            system("cls");
    }
}

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
    int decisao=0;
    system("cls");
    printf("BEM VINDO AO BANCO TUPINIQUIM\n");
    printf("-----------------------------\n");
    printf("Para inserir sua conta siga os passos...\n");

    criarConta(pessoa);
    mostrarConta(pessoa);
    
    printf("\n\nDeseja fazer uma transferencia bancaria?");
    printf("\n1.SIM\n2.NAO");
    do{
        scanf("%d", &decisao);
    }while (decisao!=1 && decisao!=2);
    
    float transferido=0;
    if(decisao==1){
        do{
            //system("cls");
            printf("\nQuanto deseja transferir?\n");
            scanf("%f", &transferido);
            if(transferido>pessoa[0].saldo)
                printf("\nSaldo insuficiente...");
        }while(transferido>pessoa[0].saldo);

        pessoa[0].saldo-=transferido;
        pessoa[1].saldo+=transferido;
        printf("\nTransferencia feita com sucesso");
        printf("\nPressione ENTER para visualizar o saldo das contas");
        getch();
        mostrarConta(pessoa);
    }

    system("cls");
    printf("Obrigado pela preferencia");  
    return 0;
}