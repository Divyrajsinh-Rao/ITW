#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first=NULL;
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

node *search(node *p, int x)
{
    while (p)
    {
        if (x == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

node *Lsearch(node *p, int x)
{
    node *q = NULL;
    while (p)
    {
        if (x == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

node *Rsearch(node *p, int x)
{
    if (p == 0)
        return NULL;
    if (x == p->data)
        return p;
    return Rsearch(p->next, x);
}

int main()
{
    int arr[] = {5, 8, 6, 94, 3, -10, 0};
    create(arr, 7);
    node *p = search(first, -10);
    if (p)
        printf("found %d\n", p->data);
    else
        printf("Not found\n");
    p = Lsearch(first, 0);
    if (p)
        printf("found %d\n", p->data);
    else
        printf("Not found\n");
    p = Rsearch(first, 77);
    if (p)
        printf("found %d\n", p->data);
    else
        printf("Not found\n");
}