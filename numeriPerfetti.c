#include <stdio.h>

int main(){
    int n = 10000;
    int sommaFinale = 0;

    for(int i = 0; i<n; i++){
        int somma = 0;
        for(int k = 1; k<i; k++){
            if(i % k == 0){
                somma += k;
            }
        }
        if(somma == i){
            sommaFinale += i;
        }
    }

    printf("\n%d\n", sommaFinale);

    return 0;
}