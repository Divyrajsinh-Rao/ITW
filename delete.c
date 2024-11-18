#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int delete(node *p, int pos)
{
    node *q = NULL;
    int x = INT_MIN;

    if (pos == 1)
    {
        x = p->data;
        first = p->next;
        free(p);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }
    return x;
}

int main()
{
    int arr[] = {5, 8, 6, 94, 3, -10, 0};
    create(arr, 7);
    int x = delete (first, 5);
    display(first);
    printf("\n");
    if (x != INT_MIN)
        printf("%d deleted\n", x);
    return 0;
}