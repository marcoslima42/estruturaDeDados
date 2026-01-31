#include <stdio.h>
#include <stdlib.h>

struct nod{
    int info;
    struct nod *prox;
    struct nod *ant;
};
typedef struct nod Nod;

struct listad{
    Nod *ini, *fim;
}; 
typedef struct listad Listad;

//prototipos de lista
Listad* criar_listad();
Nod* cria_nod(int info);
void insere_inicio_listad(int info, Listad *L);
void insere_fim_listad(int info, Listad *L);
void mostra_listad(Listad *L);
Nod* remove_inicio(Listad *L);
int inicio(Listad *L);//consulta inicio 
Listad* libera_listad(Listad *L);

typedef Listad Fila;
//prototipos de fila
Fila* cria_fila();
void enqueue(Fila*, int);
Nod* dequeue(Fila*);
int consulta_inicio(Fila*);
int fila_vazia(Fila*);
Fila* libera_fila(Fila*);

int main(){
    Fila *f = cria_fila();
    enqueue(f, 10);
    enqueue(f, 5);
    enqueue(f, 30);
    enqueue(f, 15);

    printf("inicio da fila:%d\n", inicio(f));

    printf("saiu: %d\n", dequeue(f)->info);

    printf("inicio da fila:%d\n", inicio(f));

    f = libera_fila(f);


    return 0;
}

Fila* cria_fila()
{
    Fila* f = criar_listad();
    return f;
}
void enqueue(Fila *f, int valor)
{
    insere_fim_listad(valor,f);
}
Nod* dequeue(Fila *f)
{
    return remove_inicio(f);

}
int consulta_inicio(Fila*f)
{
    return inicio(f);

}
int fila_vazia(Fila* f)
{
    int res = 1;
    if (f->ini == NULL)
    {
        res = 0;
    }
    return res;
}
Fila* libera_fila(Fila *f)
{
    libera_listad(f);
    return NULL;
}

Listad* criar_listad()
{
    Listad *L = (Listad*)malloc(sizeof(Listad));
    L->ini = L->fim = NULL;
    return L;
}

Nod* cria_nod(int info)
{
    Nod *novo= (Nod*)malloc(sizeof(Nod));
    novo->info = info;
    novo->ant = novo->prox = NULL;
    return novo;
}

void insere_inicio_listad(int info, Listad *L)
{
    Nod *novo = cria_nod(info);

    if (L->ini == NULL)
    {
        L->ini = L->fim = novo;
    }
    else
    {
        novo->prox = L->ini;
        L->ini->ant = novo;
        L->ini = novo;
    }
}

void insere_fim_listad(int info, Listad *L)
{
    Nod* novo = cria_nod(info);

    if (L->ini==NULL)
    {
        L->ini = L->fim = novo;
    }
    else
    {
        novo->ant = L->fim;
        L->fim->prox = novo;
        L->fim = novo;
    }
}

void mostra_listad(Listad *L)
{
    Nod *aux = L->ini;

    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}
Listad* libera_listad(Listad *L)
{
    Nod* aux;

    while(L->ini != NULL)
    {
        aux = L->ini;
        L->ini = L->ini->prox;
        free(aux);
    }
    free(L);
    return NULL;
}

Nod* remove_inicio(Listad *L)
{
    Nod* aux = NULL;
    if (L != NULL && L->fim != NULL) //caso haja elemento
    {
        aux = L->ini;
        if (L->ini == L->fim)
        {   
            L->ini = L->fim = NULL;
        }
        else
        {
            L->ini = L->ini->prox;
            L->ini->ant = NULL;
        }
    }
    return aux;
}
int inicio(Listad *L)//consulta inicio 
{
    int valor_inicio = -1;
    if (L != NULL && L->fim != NULL) //caso haja elemento
    {
        valor_inicio = L->ini->info;
    }
    return valor_inicio;
}