#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
typedef struct Node node;

void create(int arr[], int n)
{
    node *p, *last;
    first = (node *)malloc(sizeof(node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        p = (node *)malloc(sizeof(node));
        p->data = arr[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void create1(int arr[], int n)
{
    node *p, *last;
    second = (node *)malloc(sizeof(node));
    second->data = arr[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        p = (node *)malloc(sizeof(node));
        p->data = arr[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void Rdisplay(node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
}

void Concat(node *p, node *q)
{
    while (p->next)
        p = p->next;
    p->next = q;
    third = first;
}

int main()
{
    int A[] = {5, 8, 6, 94, 3, -10, 0};
    create(A, 7);
    int B[] = {15, 885, 6, 5, 3, 48, 35, 53, -84};
    create1(B, 9);
    Concat(first, second);
    Rdisplay(third);
    return 0;
}