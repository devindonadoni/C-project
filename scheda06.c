#include <stdio.h>

int produttoria(int i){
    if(i == 1) return 2;
    return produttoria(i-1) * (i+1);
}

int sommatoria(int n){
    if(n == 1) return produttoria(1);
    return sommatoria(n-1) + n * produttoria(n);
}

int prodottoJ(int j, int i){
    int prodotto = 1;
    for (int k = 1; k <= j; k++)
    {
        prodotto *= (i+j+k);
    }
    return prodotto;
}

int prodottoI(int i){
    int prodotto = 1;
    for (int j = 1; j <= i; j++)
    {
        prodotto *= prodottoJ(j, i);
    }
    return prodotto;
}

int sommatoriaN(int n){
    int somma = 0;
    for (int i = 1; i <= n; i++)
    {
        somma += prodottoI(i);
    }
    return somma;
}

int sommatoria5_ric(int n){
    if(n == 1) return 3;
    return sommatoria5_ric(n-1) + prodottoI(n);
}

// ------------------------------------------------------------------------------------------

long long p(int i, int j, int k) {
    if ((i + j + k) % 2 == 0) return 1;
    return 0;
}

long long q(int i, int j, int k) {
    if ((i * j * k) % 3 == 0) return 1;
    return 0;
}

long long produttoriaJ(int i, int j) {
    long long prodotto = 1;
    for (int k = 1; k <= j; k++) {   
        prodotto *= ((p(i, j, k) * ((long long)(i + j + k) * (i + j + k)))  
                  + ((q(i, j, k)) * (i - j + k)));
    }
    return prodotto;
}

long long produttoriaI(int i) {
    long long prodotto = 1;
    for (int j = 1; j <= i; j++) {
        prodotto *= produttoriaJ(i, j);
    }
    return prodotto;
}

long long funzione7(int n) {
    long long somma = 0;
    for (int i = 1; i <= n; i++) {
        somma += produttoriaI(i);
    }
    return somma;
}


// ------------------------------------------------------------------------------------------

int main(){
    int n;

    while (1)
    {
        printf("Inserisci n-->");
        scanf("%d", &n);
    
        printf("Risultato della funzione 4 ---> %d\n", sommatoria(n));
        printf("Risultato della funzione 5 ---> %d\n", sommatoriaN(n));
        printf("Risultato della funzione 5_ric ---> %d\n", sommatoria5_ric(n));
        printf("Risultato della funzione 7 ---> %d\n", funzione7(n));
    }
}