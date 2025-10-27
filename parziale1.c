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
    if(n == 0) return a0;
    if(n == 1) return a1;
    for(int i = 2; i <= n; i++){
        if(i%2 == 0){
            risultato = ((i + 3) * (a0 - 2))/ a1;
        }else{
            risultato = ((i + 3) * (a1 - 2))/ a0;
        }
        a0 = a1;
        a1 = risultato;
    }
    return risultato;
}

int sommatoria_ric(int n){
    printf("ultimo numero=%d\n", n%10);
    printf("numeri prima=%d\n", n/10);
    if(n < 10) return n;
    return n%10 + sommatoria_ric(n/10);
}

int main(){
    int n;
    printf("valore n-->");
    scanf("%d", &n);

    printf("a1-1) risultato = %d\n" , prodotto(n) * sommatoria1(n));
    
    for(int i = 0; i <= n; i++){
        printf("S(%d) = %f\n" , i, successione(i));
    }



    printf("a2-1) risultato = %d\n" , sommatoria_ric(n));
    

}