#include <stdio.h>

void push(int *stack, int valor);
void pop(int *stack);

int main(){
    int stack[5];

    push(stack, 5);
    push(stack, 4);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);
    //fazer push com pilha cheia;
    push(stack, 99);

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    //fazer pop com a lista vazia

    
    
    
    return 0; 
}