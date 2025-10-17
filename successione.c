#include <stdio.h>

float successione(int n){
    float variabile = 0.5;

    if(n == 1){
        return 0.5;
    }else{
        for(int i = 1; i<n; i++){
            variabile = (variabile+1)/2;
        }
        return variabile;
    }
}

int main(){
    int n = 0;
    printf("Inserisci n\n");
    scanf("%d", &n);
    
    printf("la successione vale = %f", successione(n));
    
    return 0;
}