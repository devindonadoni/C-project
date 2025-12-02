#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void push(Stack **s, int value)
{
    if ((*s) == NULL)
    {
        (*s) = malloc(sizeof(Stack));
        (*s)->top = NULL;
    }

    Node *newnode = malloc(sizeof(Node));
    newnode->value = value;
    newnode->next = (*s)->top;
    (*s)->top = newnode;
}

int pull(Stack **s)
{
    if ((*s) == NULL)
        return -1;

    Node *tmp = (*s)->top;
    int value = (*s)->top->value;
    (*s)->top = (*s)->top->next;
    free(tmp);

    return value;
}

void stampaPila(Stack **s, int n)
{
    printf("\n[");

    if ((*s) != NULL)
    {

        Node *curr = (*s)->top; // puntatore temporaneo alla cima

        for (int i = 0; i < n && curr != NULL; i++)
        {
            printf("%d", curr->value);
            if (i < n - 1 && curr->next != NULL)
                printf(", ");
            curr = curr->next;
        }
    }

    printf("]\n");
}

Stack *remove_even(Stack *s)
{
    Stack *tmp = NULL;
    Stack *newStack = NULL;
    while (s->top != NULL)
    {
        if ((s->top->value) % 2 == 0)
        {
            pull(&s);
        }
        else
        {
            // AGGIUNGO DENTRO NUOVO STACK + AGGIORNO IL TOP al next
            push(&tmp, s->top->value);
            s->top = s->top->next;
        }
    }

    while (tmp != NULL && tmp->top != NULL)
    {
        push(&newStack, pull(&tmp));
    }
    return newStack;
}

int main()
{
    int n = 5;
    int valore;
    Stack *s = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &valore);
        push(&s, valore);
    }

    stampaPila(&s, n);

    Stack *new = remove_even(s);
    stampaPila(&new, n);
}