#include <stdio.h>
#include <stdlib.h>

int main() {
    int fatorial[8]={1, 2, 6, 24, 120, 720, 5040, 40320};
    int n=0, n2=0, k=0;

    scanf("%d", &n);
    while(n!=n2){
        for(int i=7; i>=0; i--){
            if(fatorial[i]<=n && fatorial[i]+n2<=n){
                n2+=fatorial[i];
                k++;
            }
            //ja incrementado perguntar se e possivel incrementar novamente com a mesma posicao de fatorial
            if(fatorial[i]<=n && fatorial[i]+n2<=n)
                i++;
        }
    }

    printf("%d", k);
    
    return 0;
}