#include <stdio.h>
#include <stdlib.h>

struct time{
    char letra;
    char nome[30];
    int continente;
    int qtd_partidas; 
    int gols_aFavor;
    int gols_contra;
    int saldo_gols;
};
typedef struct time Time;

struct partida{
    int codigo;
    char time1;
    char time2;
    int gols_time1;
    int gols_time2;
};
typedef struct partida Partida;

void ReceberTimes(Time VetorTimes[], int tamanho){
    for(int i=0; i<tamanho; i++){
        gets(VetorTimes[i].letra);
        scanf("%d", &VetorTimes[i].continente);
    }
}

void ReceberPartidas(Partida VetorPartidas[], int tam_part, Time VetorTimes[], int tam_times){
    
}

int main(){
    int tam;
    int *VetorTimes; //ponteiro para alocar memoria

    scanf("%d", &tam);
    VetorTimes=(int *)malloc(tam*sizeof(int));
    ReceberTimes(VetorTimes, tam);
    return 0;
}