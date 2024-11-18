#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
typedef struct Node node;

void create(int arr[], int n, node **q)
{
    node *p, *last;
    *q = (node *)malloc(sizeof(node));
    (*q)->data = arr[0];
    (*q)->next = NULL;
    last = *q;

    for (int i = 1; i < n; i++)
    {
        p = (node *)malloc(sizeof(node));
        p->data = arr[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

int main()
{
    int arr[] = {5, 8, 6, 94, 3, -10, 0};
    create(arr, 7, &first);
}