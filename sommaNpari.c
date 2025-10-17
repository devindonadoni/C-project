#include <stdio.h>

int main(){

    int n = 12;
    int somma = 0;
    while (n > 0)
    {
        if(n%2 == 0){
            somma += n;
        }
        n--;
    }
    
    printf("somma = \n");
    printf("%d", somma);
    return 0;
}