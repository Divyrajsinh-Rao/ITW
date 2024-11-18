#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
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

void display(node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void Sinsert(node *p, int x)
{
    node *t;
    t = (node *)malloc(sizeof(node));
    t->data = x;
    t->next = NULL;
    node *q = NULL;
    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            q->next = t;
            t->next = p;
        }
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    create(arr, 10);
    Sinsert(first, 10);
    display(first);
    printf("\n");
    return 0;
}