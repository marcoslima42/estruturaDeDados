#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        //gets(VetorTimes[i].letra); //verificar se o 'gets' pode ser usado para o input de um char de uma posicao
        fflush(stdin);
        VetorTimes[i].letra = getchar();
        fflush(stdin);
        gets(VetorTimes[i].nome);
        scanf("%d", &VetorTimes[i].continente);
    }
}

void ReceberPartidas(Partida VetorPartidas[], int tam_part, Time VetorTimes[], int tam_times){
    int partida=0;
    char letraTime1, letraTime2;
    scanf("%d", &partida);
    for(int i=0; i<tam_part; i++){
        scanf("%d", &VetorPartidas[i].codigo);
        //gets(VetorPartidas[i].time1);
        fflush(stdin);
        VetorPartidas[i].time1=getchar();
        //gets(VetorPartidas[i].time2);
        fflush(stdin);
        VetorPartidas[i].time2=getchar();
        scanf("%d", &VetorPartidas[i].gols_time1);
        scanf("%d", &VetorPartidas[i].gols_time2);
        
        //processar os dados da partida
        for(int j=0; j<tam_times; j++){
            //time1
            int saldoGols=0;
            if(VetorTimes[j].letra==VetorPartidas[i].time1){
                //gols a favor
                VetorTimes[j].gols_aFavor+=VetorPartidas[i].gols_time1;
                //gols contra
                VetorTimes[j].gols_contra+=VetorPartidas[i].gols_time2;
                //saldo de gols
                saldoGols=VetorTimes[j].gols_aFavor-VetorTimes[j].gols_contra;
                VetorTimes[j].saldo_gols+=saldoGols; 
                VetorTimes[j].qtd_partidas++;
            }
            //time2
            int saldoGols2=0;
            if(VetorTimes[j].letra==VetorPartidas[i].time2){
                //gols a favor
                VetorTimes[j].gols_aFavor+=VetorPartidas[i].gols_time2;
                //gols contra
                VetorTimes[j].gols_contra+=VetorPartidas[i].gols_time1;
                //saldo de gols
                saldoGols2=VetorTimes[j].gols_aFavor-VetorTimes[j].gols_contra;
                VetorTimes[j].saldo_gols+=saldoGols2; 
                VetorTimes[j].qtd_partidas++;
            }
        }
    }
}

Time MelhorSaldoGols(Time VetorTimes[], int tamanho){
    int maior=VetorTimes[0].saldo_gols;
    int maiorI=0;
    for(int i=0; i<tamanho; i++){
        if(VetorTimes[i].saldo_gols>maior){
            maior=VetorTimes[i].saldo_gols;
            maiorI=i;
        }
    }
    return VetorTimes[maiorI];
}

Time PiorSaldoGols(Time VetorTimes[], int tamanho){
    int menor=VetorTimes[0].saldo_gols;
    int menorI=0;
    for(int i=0; i<tamanho; i++){
        if(VetorTimes[i].saldo_gols<menor){
            menor=VetorTimes[i].saldo_gols;
            menorI=i;
        }
    }
    return VetorTimes[menorI];
}

Time MelhorClassificadoContinente(Partida VetorPartidas[], int tam_part, Time VetorTimes[], int tam_times, int continente){
    int maior=0;
    int maiorContinenteI=0;
    int empate[tam_times];//pq nao consigo criar vetor com a variavel [tam_times]?

    for(int i=0; i<tam_times; i++){
        if(VetorTimes[i].continente==continente && VetorTimes[i].qtd_partidas>maior){
            maior=VetorTimes[i].qtd_partidas;
            maiorContinenteI=i;
        }
    }
    return VetorTimes[maiorContinenteI];
}

int main(){
    int tam;
    Time *VetorTimes; //ponteiro para alocar memoria

    scanf("%d", &tam);
    VetorTimes=(Time *)malloc(tam*sizeof(Time));
    ReceberTimes(VetorTimes, tam);

    //apos alocacao e preenchimento do VetorTime, receber partidas
    //antes, alocar o vetor de partidas que sempre sera "m-1"
    Partida *VetorPartidas; 
    int tamPartidas=0;
    scanf("%d", &tamPartidas);
    VetorPartidas=(Partida *)malloc(tamPartidas*sizeof(Partida));
    ReceberPartidas(VetorPartidas, tamPartidas, VetorTimes, tam);

    Time melhorSaldoGols;
    Time piorSaldoGols;

    melhorSaldoGols=MelhorSaldoGols(VetorTimes, tam);
    piorSaldoGols=PiorSaldoGols(VetorTimes, tam);

    //criacao e processamento do melhor classificado de cada continente

    Time america1, europa2, africa3, asia4, oceania5;

    america1=MelhorClassificadoContinente(VetorPartidas, tamPartidas, VetorTimes, tam, 1);
    europa2=MelhorClassificadoContinente(VetorPartidas, tamPartidas, VetorTimes, tam, 2);
    africa3=MelhorClassificadoContinente(VetorPartidas, tamPartidas, VetorTimes, tam, 3);
    asia4=MelhorClassificadoContinente(VetorPartidas, tamPartidas, VetorTimes, tam, 4);
    oceania5=MelhorClassificadoContinente(VetorPartidas, tamPartidas, VetorTimes, tam, 5);

    printf("%c\n", melhorSaldoGols.letra);
    printf("%c\n", piorSaldoGols.letra);
    
    printf("%d:%c\n", america1.continente, america1.letra);
    printf("%d:%c\n", europa2.continente, europa2.letra);
    printf("%d:%c\n", africa3.continente, africa3.letra);
    printf("%d:%c\n", asia4.continente, asia4.letra);
    printf("%d:%c\n", oceania5.continente, oceania5.letra);

    //desaloca memoria
    free(VetorTimes);
    free(VetorPartidas);
    return 0;
}