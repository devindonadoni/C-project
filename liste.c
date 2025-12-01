#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valore;
    struct Nodo *next;
} Nodo;

void inserimentoTesta(Nodo **head, int valore)
{
    Nodo *nuovo = malloc(sizeof(Nodo));
    nuovo->valore = valore;
    nuovo->next = *head;
    *head = nuovo;
}

void inserimentoCoda(Nodo **head, int valore)
{
    Nodo *nuovo = malloc(sizeof(Nodo));
    nuovo->valore = valore;
    nuovo->next = NULL;

    if (*head == NULL)
    { // se la lista e' vuota e ovvio che la nuova head diventa nuovo
        *head = nuovo;
    }
    else
    {
        Nodo *current = *head; // in questo caso head e current puntano allo stesso indrizzo di memoria
        while (current->next != NULL)
        {
            current = current->next;
        } // scorrimento fino alla fine e collega
        current->next = nuovo;
    }
}

void stampaLista(Nodo **head)
{
    Nodo *current = *head;

    while (current != NULL)
    {
        printf("%d, ", current->valore);
        current = current->next;
    }
}

void inserimentoMiddle(Nodo **head, int valore)
{
    Nodo *nuovo = malloc(sizeof(Nodo));
    nuovo->valore = valore;
    nuovo->next = NULL;

    if (*head == NULL)
    {
        *head = nuovo;
    }
    else
    {
        Nodo *current = *head;
        Nodo *prec = current;
        current = current->next;

        nuovo->next = current;
        prec->next = nuovo;
    }
}

Nodo *popolaListaScan()
{
    int n = 0;
    Nodo *final = NULL;
    while (n != -1)
    {
        scanf("%d", &n);
        if (n != -1)
        {
            Nodo *nuovo = malloc(sizeof(Nodo));
            nuovo->valore = n;
            nuovo->next = NULL;
            if (final == NULL)
            {
                final = nuovo;
            }
            else
            {
                Nodo *current = final;
                while (current->next != NULL)
                {
                    current = current->next;
                }
                current->next = nuovo;
            }
        }
    }

    return final;
}

int contaLunghezza(Nodo *head)
{
    Nodo *current = head;
    int contatore = 0;
    while (current != NULL)
    {
        contatore++;
        current = current->next;
    }
    return contatore;
}

void arrayToList(Nodo **head, int *b)
{
    Nodo *current = *head;

    for (int i = 0; i < 5; i += 2)
    {
        Nodo *nuovo = malloc(sizeof(Nodo));
        nuovo->valore = *(b + i);
        nuovo->next = NULL;

        if (*head == NULL)
        {
            *head = nuovo;
        }
        else
        {
            Nodo *current = *head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = nuovo;
        }
    }
}

void addIntheMiddle(Nodo **head, int *b)
{
    int elementi = contaLunghezza(*head);
    int n = 0;
    Nodo *current = *head;
    Nodo *prec;

    while (n <= elementi / 2)
    {
        prec = current;
        current = current->next;
        n++;
    }

    Nodo *nuovo = malloc(sizeof(Nodo));
    nuovo->valore = *(b + 3);
    nuovo->next = current;
    prec->next = nuovo;
}

void inserimentoOrdinato(Nodo **head, int valore)
{
    Nodo *current = *head;
    Nodo *prec;
    Nodo *nuovo = malloc(sizeof(Nodo));
    nuovo->valore = valore;

    if (valore <= current->valore)
    {
        nuovo->next = current;
        *head = nuovo;
    }
    else
    {
        while (current != NULL && valore > current->valore)
        {
            prec = current;
            current = current->next;
        }
        prec->next = nuovo;
        nuovo->next = current;
    }
}

void eliminaDuplicati(Nodo **head)
{
    Nodo *toCheck = *head;
    Nodo *current;
    Nodo *prec;

    while (toCheck != NULL)
    {
        prec = toCheck;
        current = toCheck->next;

        while (current != NULL)
        {

            if (current->valore == toCheck->valore)
            {
                Nodo *temp = current;
                prec->next = current->next;
                current = current->next;
                free(temp);
            }
            else
            {
                prec = current;
                current = current->next;
            }
        }

        toCheck = toCheck->next;
    }
}

void invertiLista(Nodo **head)
{
    Nodo *current = *head;02.
    Nodo *prev =    Nodo *newHead = *head;
 NULL;
    int n = contaLunghezza(*head);
    for (int i = n; i > 0; i--)
    {
        int s = 0;
        while (s < i-1)
        {
            prev = current;
            current = current->next;
            s++;
        }
        current->next = prev;
    }
}

int main()
{
    Nodo *head = NULL;
    // inserimentoTesta(&head, 4);
    // inserimentoTesta(&head, 8);
    // inserimentoCoda(&head, 10);
    // inserimentoMiddle(&head, 5);
    // stampaLista(&head);

    //! ESERCIZIO 1
    // head = popolaListaScan();
    // stampaLista(&head);
    // printf("\n%d",contaLunghezza(head));

    // !ESERCIZIO 2
    // int *b = malloc(sizeof(int) * 5 ); // arrayd di dimensione 5
    // *(b + 0) = 6;
    // *(b + 1) = 22;
    // *(b + 2) = 8;
    // *(b + 3) = 4;
    // *(b + 4) = 7;
    // arrayToList(&head, b);
    // addIntheMiddle(&head, b);
    // stampaLista(&head);

    // !ESERCIZIO 3
    // inserimentoCoda(&head, -2);
    // inserimentoCoda(&head, 5);
    // inserimentoCoda(&head, 7);
    // inserimentoCoda(&head, 11);
    // stampaLista(&head);
    // int k;
    // printf("\nK-->");
    // scanf("%d", &k);
    // inserimentoOrdinato(&head, k);
    // stampaLista(&head);

    // !ESERCIZIO 4
    // inserimentoCoda(&head, 1);
    // inserimentoCoda(&head, 8);
    // inserimentoCoda(&head, 7);
    // inserimentoCoda(&head, 1);
    // inserimentoCoda(&head, 8);
    // inserimentoCoda(&head, 1);
    // stampaLista(&head);

    // eliminaDuplicati(&head);
    // printf("\nSTAMPATA\n");
    // stampaLista(&head);

    // ?ESERCIZIO 5
    // inserimentoCoda(&head, 1);
    // inserimentoCoda(&head, 8);
    // inserimentoCoda(&head, 7);
    // inserimentoCoda(&head, 11);
    // inserimentoCoda(&head, 1);
    // stampaLista(&head);

    // invertiLista(&head);
    // printf("\nSTAMPATA\n");
    // stampaLista(&head);

    // !ESERCIZIO 6

}