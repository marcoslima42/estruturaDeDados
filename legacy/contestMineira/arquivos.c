#include <stdio.h>
#include <stdlib.h>

int main(){
    int n=0, b=0;
    scanf("%d %d", &n, &b);
    
    int vetor[n];
    
    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    printf("\n\n");
    /*for(int i=0; i<n; i++){
        printf(" %d ", vetor[i]);
    }*/
    
    //do menor ao maior
    int aux=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(vetor[j]>vetor[j+1]){
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
        }
    }
    
    int totalB=0, prox=0, qtdPastas=0;
    for(int i=n-1; i>=0; i--){
        if(vetor[i]<=b){
            totalB+=vetor[i];
        }
        if(totalB==b){
            totalB=0;
            qtdPastas++;
        }
    }

    printf("%d\n", qtdPastas);
    
    return 0;
}