#include <stdio.h>

int main(){
    int n = 5;
    int prodotto = 1;

    while(n>0){
        prodotto *= n;
        
        n--;
    }

    printf("%d", prodotto);

    return 0;
}