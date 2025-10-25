#include <stdio.h>

int sommatoria1(int n){
    if(n == 1) return 1;
    return n + sommatoria1(n - 1);
}

int prodotto(int n){
    if(n == 1) return 2;
    return 2 * prodotto(n-1); 
}

float successione(int n){
    float a0 = 1.0;
    float a1 = 2.0;
    float risultato = 0.0;
    for(int i = 2; i <= n; i++){
        if(i%2 == 0){
            risultato = ((n + 3) * (a0 - 2))/ a1;
        }else{
            risultato = ((n + 3) * (a1 - 2))/ a0;
        }
        a0 = a1;
        a1 = risultato;
    }
    
}

int main(){
    int n;
    printf("valore n-->");
    scanf("%d", &n);

    printf("a1-1) risultato = %d\n" , prodotto(n) * sommatoria1(n));
    printf("a1-2) risultato = %f\n" , successione(n));
}