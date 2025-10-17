#include <stdio.h>

float media(float somma, int contatore);

int main(){
    float numero = 1;
    float somma =  0;
    int contatore = 0;

    while (numero != 0){
        printf("Inserisci il tuo numero\n");
        scanf("%f", &numero);
        somma += numero;
        if(numero != 0){
            contatore ++;
        }
        printf("numero inserito = %f\n", numero);
        printf("attuale somma = %f\n", somma);
        printf("numeri inseriti = %d\n", contatore);
    }

    printf("Esecuzione ferma perche hai premuto 0\n");
    if (contatore > 0) {
        printf("La media è = %f \n", media(somma, contatore));
    } else {
        printf("Nessun numero inserito, media non calcolabile.\n");
    }
    
}

float media(float somma, int contatore){
    return somma/contatore;
}