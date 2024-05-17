#include <stdio.h>
#include <stdlib.h>
#define dim 10

// void imprimir(int matriz[dim][dim]){
//     for(int i=0; i<10; i++){
//         for(int j=0; j<10; j++){
//             printf("%d", matriz[i][j]);
//         }
//         printf("\n");
//     }
    
// }

void inicializar_matriz(int matriz[][dim]){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            matriz[i][j]=0;
        }
    }
}

int main(){
    int matriz[dim][dim];
    inicializar_matriz(matriz);
    // imprimir(matriz);
    
    return 0; 
}