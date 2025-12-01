#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int stampaArray(int array[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", array[i]);
    }
    printf("]\n");
}

int sottoArray(int array[], int n, int l)
{
    int sottoArray[l];
    for (int i = 0; i <= n - l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            sottoArray[j] = array[i + j];
        }
    }
}

void invertiArray(int a[], int n)
{
    int aInverito[n];
    for (int i = 0; i < n; i++)
    {
        aInverito[i] = a[(n - 1) - i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("aInverito[%d] = %d\n", i, aInverito[i]);
    }
}

void fibonacciArray(int n)
{

    int array[n], f0, f1, risultato;
    for (int i = 0; i < n; i++)
    {
        f0 = 0;
        f1 = 1;

        if (i == 0)
            risultato = f0;
        if (i == 1)
            risultato = f1;
        for (int j = 2; j <= i; j++)
        {
            risultato = f0 + f1;
            f0 = f1;
            f1 = risultato;
        }
        array[i] = risultato;
    }
    stampaArray(array, n);
}

void compressioneArray()
{
    int n;
    printf("Inserisci n: ");
    scanf("%d", &n);

    int *p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        printf("inserisci array[%d]: ", i);
        scanf("%d", &p[i]);
    }

    int *arraCompresso = NULL;
    int dimCompresso = 0;

    for (int i = 0; i < n; i++)
    {
        int valore = *(p + i);
        if (valore != 0)
        {
            int contatore = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (*(p + j) == valore)
                {
                    contatore++;
                    *(p + j) = 0;
                }
            }

            dimCompresso += 2;
            arraCompresso = realloc(arraCompresso, sizeof(int) * dimCompresso);
            arraCompresso[dimCompresso - 2] = contatore;
            arraCompresso[dimCompresso - 1] = valore;
        }
    }

    // oppure creo un array normale, tengo traccia della dimesione che deve avere l'array finale e passo quella in stampa

    printf("\nArray compresso: ");
    stampaArray(arraCompresso, dimCompresso);

    free(p);
    free(arraCompresso);
}

void serieSommatoria(int n)
{
    float array[n];
    for (int i = 0; i < n; i++)
    {
        float risultato = 0.0;
        for (int j = 0; j <= i; j++)
        {
            float combinazione = 1.0 / ((2 * j + 1) * (2 * j + 1));
            risultato += combinazione;
        }
        array[i] = risultato;
    }

    // STAMPA
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf(" %f", array[i]);
    }
    printf("]\n");
}

int palindromoArray()
{
    int n;
    printf("Inserisci n: ");
    scanf("%d", &n);

    int *p = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        printf("inserisci array[%d]: ", i);
        scanf("%d", &p[i]);
    }

    int palindromo = 1;
    int ciao = n / 2;
    for (int i = 0; i <= n / 2; i++)
    {
        if (p[i] != p[(n - 1) - i])
            palindromo = 0;
    }

    stampaArray(p, n);

    free(p);
    return palindromo;
}

int main()
{
    int scelta;
    do
    {

        printf("-------------------\n");
        printf("1) Inverti Array\n");
        printf("2) Fibonacci\n");
        printf("3) Serie Sommatoria\n");
        printf("4) Palindromo\n");
        printf("5) Compressione Array\n");
        printf("0) EXIT\n");
        printf("-------------------\n");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
        {
            int n;
            printf("Dimesione Array--> ");
            scanf("%d", &n);

            int array[n];
            for (int i = 0; i < n; i++)
            {
                printf("array[%d]= ", i);
                scanf("%d", &array[i]);
            }

            invertiArray(array, n);
            break;
        }
        case 2:

            int k;

            printf(">N--> ");
            scanf("%d", &k);
            fibonacciArray(k);
            break;
        case 3:
            int j;

            printf(">N--> ");
            scanf("%d", &j);
            serieSommatoria(j);
            break;
        case 4:
            printf("PALINDROMO %d\n", palindromoArray());
            break;
        case 5:
            compressioneArray();
            break;
        default:
            break;
        }
    } while (scelta != 0);
}