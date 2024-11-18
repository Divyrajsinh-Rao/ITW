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

void Rdisplay(node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
}

void duplicate(node *p)
{
    node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main()
{
    int arr[] = {10, 10, 20, 50, 50, 70, 70, 80, 80, 90, 90, 90, 100};
    create(arr, 13);
    duplicate(first);
    Rdisplay(first);
    printf("\n");
    return 0;
}