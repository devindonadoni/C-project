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
    if(n < 10) return n;
    return n%10 + sommatoria_ric(n/10);
}

int produttoria_ric(int n){
    if(n < 10) return n;
    return n%10 * produttoria_ric(n/10);
}

float myfun_iter(int n){
    float a1 = -1.0;
    float a2 = 0.0;
    float risultato = 0;
    for (int i = 3; i <= n; i++)
    {
        if(i%2 == 0)
            risultato = ((0.5 * a1) - a2 + 1);
        else
            risultato = ((2*i) + a2 + 1 + (2*a1));
        
        a1 = a2;
        a2 = risultato;
    }

    return risultato;
    
}

float myfun_rec(int n){
    if(n == 1) return -1;
    if(n == 2) return 0;
    if(n%2 == 0)
        return 0.5 * myfun_rec(n - 2) - myfun_rec(n - 1) + 1;
    else
        return (2 * n) + myfun_rec(n - 1) + 1 + (2 * myfun_rec(n - 2));
}

float successioneIterativa(int n){
    float s1 = 4;
    float s2 = 5;
    float risultato = 0;

    for (int i = 3; i <= n; i++)
    {
        if(s2/2 >= (3 * s1)){
            risultato = (s1 * s2)/i;
        }else{
            risultato = (s1 + s2)/i;
        }
        s1 = s2;
        s2 = risultato;
    }

    return risultato;
}

float produttoria_ric_succ(int k, int j){
    if(k == j) return successioneIterativa(k);
    return successioneIterativa(j) * produttoria_ric_succ(k, j+1);
}

float myfun_ric_n(int n){
    if(n == 0) return 1.0;
    if(n == 1) return 2.0;                                                                                                                //a(2) = 1.5    //a(3) = -0.25    //a(4) = 0.625
    if(n%2 == 0){
        return (myfun_ric_n(n-2) + myfun_ric_n(n - 1) )/2.0;
    }else{
        return (myfun_ric_n(n-1) - myfun_ric_n(n - 2) )/2.0;
    }
}

int main(){
    int n;
    int j;
    printf("valore n-->");
    scanf("%d", &n);

    printf("a1-1) risultato = %d\n" , prodotto(n) * sommatoria1(n));
    
    printf("a1-2 RISULTATi\n");
    for(int i = 0; i <= n; i++){
        printf("-S(%d) = %f\n" , i, successione(i));
}

    printf("a2-1) risultato = %d\n" , sommatoria_ric(n));
    printf("a2-2) risultato = %d\n" , produttoria_ric(n));
    
    printf("a1-3) risultato successione iterativa = %f\n", myfun_iter(n));
    printf("a1-3) risultato successione ricorsiva = %f\n", myfun_iter(n));

    printf("a2-3) risultato successione iterativa = %f\n", successioneIterativa(n));

    // printf("Inserisci j-->");
    // scanf("%d", &j);
    // printf("a3-1) risultato produttoria della successione = %f\n", produttoria_ric_succ(n, j));

    printf("a1-4) risultato della successione\n");
    for (int i = 0; i <= n; i++)
    {
        printf("-S(%d)= %f\n",i, myfun_ric_n(i));
    }
    


}