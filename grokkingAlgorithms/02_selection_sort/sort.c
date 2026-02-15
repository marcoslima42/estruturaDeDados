#include<stdio.h>
#include<stdlib.h>

int descobrirMenor(int lista[], int tam, int ini){
    int indexMenor = ini;
    for(int i=ini; i< tam; i++){
        if(lista[indexMenor] > lista[i])
            indexMenor = i;
    }
    return indexMenor;
}

int main(){
    int tam = 5;
    int lista [] = {4, 5, 1, 2, 0};

    int aux;
    
    for(int i=0; i<tam; i++){
        int indexMenor = descobrirMenor(lista, tam, i);
            aux = lista[i];
            lista[i] = lista[indexMenor];
            lista[indexMenor] = aux;
    }
    
    for(int i =0 ; i<tam; i++){
        printf("%d ", lista[i]);
    }

    printf("\n\n");
    return 0;
}