#include <stdio.h>
#include <stdlib.h>
#define xy 35
int main(){
    int n=0, b=0;
    scanf("%d %d", &n, &b);
    
    int vetor[xy];
    
    for(int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    
    
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
    
    int k=0, l=n-1, qtdPastas=0;
    while(k<l){
        if(vetor[k]+vetor[l] <= b)
            k++;

        qtdPastas++;
        l--;
    }
    printf("%d", qtdPastas);
    
    return 0;
}