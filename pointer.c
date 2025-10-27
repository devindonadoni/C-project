#include <stdio.h>

void birthday(int* age){            //? il '*' specifica che la funzione si aspetta il passaggio di una variabile tipo pointer
    (*age) ++;                          // le partentesi servono perche' altrimenti il compilatore eseguirebbe prima l'incremento rispetto al renderlo puntatore
}

int main(){
    // i puntatori sono variabili che hanno come valore l'indirizzo di memoria di un altra variabile

    int age = 25;

    printf("VALORE DELLA VARIABILE --> %d\n", age);\
    printf("INDIRIZZO DI MEMORIA CON & --> %p\n", &age);

    int *pAge = &age;    // '*' serve per creare un puntarore che stora k'indirzzo di age, il type della variabile puntatore deve quindi permettere di salvare numero
    printf("INDIRIZZO DI MEMORIA CON *pAge --> %p\n", pAge);


    
//* PASSARE PUNTATORI AD UNA FUNZIONE
    
    // birthday(age);                                                   //! questo codice stampa comunque 25 perche' all'interno della funzione senza puntatori viene creata una copia della variabile passata*/
    // printf("Tu hai %d anni\n" , age);

    birthday(pAge);
    printf("Tu hai %d anni\n" , age);
}