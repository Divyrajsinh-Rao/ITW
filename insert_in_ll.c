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

void insert(node *p, int pos, int x)
{
    node *q;
    q = (node *)malloc(sizeof(node));
    q->data = x;
    if (pos == 0)
    {
        q->next = first;
        first = q;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            p->next = q;
        }
    }
}

int main()
{
    int arr[] = {5, 8, 6, 94, 3, -10, 0};
    create(arr, 7);
    insert(first, 0, 10);
    insert(first, 5, 20);
    insert(first, 9, 40);
    insert(first, 7, 80);
    insert(first, 8, 50);
    insert(first, 5, 70);
    display(first);
    printf("\n");
    return 0;
}