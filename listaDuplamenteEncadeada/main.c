#include "lib.h"

int main(){
    ListaD* l;
    l=(ListaD*)malloc(sizeof(ListaD));
    l->inicio=NULL;
    l->fim=NULL;
    inserirFim(l, 1);
    inserirFim(l, 2);
    inserirFim(l, 3);
    inserirFim(l, 4);

    imprimirLista(l);

    return 0;
}