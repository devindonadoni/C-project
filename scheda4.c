#include <stdio.h>
#include <math.h>

int fibonacci(int intero)
{
    int somma = 0;

    if (intero == 0)
        return 0;
    else
    {
        if (intero == 1)
        {
            return 1;
        }
        else
        {
            somma += fibonacci(intero - 1) + fibonacci(intero - 2);
        }
    }
    return somma;
}

int sommatoria(int base, int potenza)
{
    int risultato = 0;
    while (potenza > 0)
    {
        risultato += pow(base, potenza);
        potenza--;
    }

    return risultato;
}

int coefficenteBinomiale(int n, int k)
{
    int fattorialeN = 1.0;
    int fattorialeK = 1.0;
    int fattorialeDen = 1.0;
    int denominatore = n - k;

    while (n > 0)
    {
        fattorialeN *= n;
        n--;
    }

    while (k > 0)
    {
        fattorialeK *= k;
        k--;
    }

    while (denominatore > 0)
    {
        fattorialeDen *= denominatore;
        denominatore--;
    }

    return fattorialeN / (fattorialeK * fattorialeDen);
}

float media(float somma, int contatore)
{
    return somma / contatore;
}

float serieOriginale(int x)
{
    float somma = 0.0;
    for (int k = 0; k <= 4; k++)
    {
        somma += pow(x, k);
    }

    return somma;
}

float serieEquivalente(int x)
{
    float somma = 0.0;
    somma = (1 - pow(x, 5)) / (1 - x);
    return somma;
}

float successione(int n)
{
    float variabile = 0.5;

    if (n == 1)
    {
        return 0.5;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            variabile = (variabile + 1) / 2;
        }
        return variabile;
    }
}

int main()
{
    int scelta;
    do
    {
        printf("\n------------------------\n");
        printf("Menù esercizi scheda 4\n");
        printf("1) Media n numer\n");
        printf("2) Equazione di secondo grado\n");
        printf("3) Calcola la successione\n");
        printf("4) Serie Geometrica x^k\n");
        printf("5) Calcola Coefficente binomiale\n");
        printf("6) Sommatoria di k^n\n");
        printf("7) Successione di Fibonacci\n");
        printf("0) EXIT\n");

        printf("------------------------\n");

        scanf("%d", &scelta);

        switch (scelta)
        {

        case 1:
            float numero = 1;
            float somma = 0;
            int contatore = 0;

            while (numero != 0)
            {
                printf("Inserisci il tuo numero\n");
                scanf("%f", &numero);
                somma += numero;
                if (numero != 0)
                {
                    contatore++;
                }
                printf("numero inserito = %f\n", numero);
                printf("attuale somma = %f\n", somma);
                printf("numeri inseriti = %d\n", contatore);
            }

            printf("Esecuzione ferma perche hai premuto 0\n");
            if (contatore > 0)
            {
                printf("La media è = %f \n", media(somma, contatore));
            }
            else
            {
                printf("Nessun numero inserito, media non calcolabile.\n");
            }
            break;
        case 3:
            int numeroSuccessione = 0;
            printf("Inserisci n\n");
            scanf("%d", &numeroSuccessione);

            printf("la successione vale = %f", successione(numeroSuccessione));
            break;
        case 4:
            int x = 0;
            printf("inserisci un valore numerico x\n");
            scanf("%d", &x);

            if (serieOriginale(x) == serieEquivalente(x))
                printf("Sommatorie equivalenti\n");
            else
                printf("Sommatorie non equivalenti\n");
            break;
        case 5:
            int n = 0;
            int k = 1;
            printf("Calcola il coefficente binomiale (n k) !!!RICORDA K>=N\n");

            while (k > n)
            {
                printf("Inserisci n--> ");
                scanf("%d", &n);

                printf("Inserisci k--> ");
                scanf("%d", &k);
            }

            printf("Il ruisultato e= %d\n", coefficenteBinomiale(n, k));
            break;

        case 6:
            int base = 0;
            int potenza = 1;

            printf("Inserisci la base-->");
            scanf("%d", &base);
            printf("Inserisci la potenza-->");
            scanf("%d", &potenza);

            printf("Il risultato e = %d\n", sommatoria(base, potenza));

            break;

        case 7:
            int intero = 0;

            printf("Inserisci numero intero per successione di Fibonacci-->");
            scanf("%d", &intero);

            for (int i = 0; i <= intero; i++)
            {
                int risultato = fibonacci(i);
                printf("F(%d) = %d\n", i, risultato);
            }
            break;

        default:
            break;
        }
    } while (scelta != 0);
}