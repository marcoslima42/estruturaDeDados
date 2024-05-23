#include "lib.h"

int main(){
    ListaD* l;
    l=(ListaD*)malloc(sizeof(ListaD));
    l->inicio=NULL;
    l->fim=NULL;
    inserirFim(l, 8);
    inserirFim(l, 6);
    inserirFim(l, 3);
    inserirFim(l, 9);
    inserirInicio(l, 5);
    imprimirLista(l);
    printf("\n\nImpressão completa, para seguir para remocao do no aperte ENTER\n");
    
    //inserirMeio(l, 9, 3);

    //imprimirLista(l);
    //free(removerNo(l,5));
    //free(removerNo(l,9));
    //printf("\n\n");
    //imprimirLista(l);

    imprimirReverso(l);
    printf("%d recursao qtd", qtdLista(l->inicio, 1));
    
    l=liberarLista(l);
    imprimirLista(l);
    return 0;
}