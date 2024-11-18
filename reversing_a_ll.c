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

void reverse(node *p)
{
    node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Rreverse(node *p, node *q)
{
    if (p)
    {
        Rreverse(p->next, p);
        p->next = q;
    }
    else
        first = q;
}

void Rdisplay(node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
}

int main()
{
    int arr[] = {5, 8, 6, 94, 3, -10, 0};
    create(arr, 7);
    reverse(first);
    Rdisplay(first);
    printf("\n");
    Rreverse(first, NULL);
    Rdisplay(first);
    printf("\n");
    return 0;
}