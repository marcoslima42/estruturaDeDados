#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam=0;
    scanf("%d", &tam);
    char ingles[1000], port[1000], frase[1000], tradutor[100], traduzido[1000];

    for(int i=0; i<tam; i++){
        scanf("%s %s", &ingles, &port);
    }
    //descobrindo se a palavra e igual
    for(int i=0; i<tam; i++){
        if(ingles[i]==frase[i] && frase[i]!='\n')
            tradutor[i]=frase[i];
    }
    
    //
    return 0;
}