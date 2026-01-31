#include<stdio.h>
void converterBinario(int n){
    if(n!=0){
        converterBinario(n/2);
        printf("%d", n%2);
    }
}
int main(){
    int n=0;

    scanf("%d", &n);
    converterBinario(n);
    
    return 0;
}