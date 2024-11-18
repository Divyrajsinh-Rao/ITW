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

int count(node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int Rcount(node *p)
{
    if (p != NULL)
    {
        return Rcount(p->next) + 1;
    }
    else
        return 0;
}

int main()
{
    int arr[] = {5, 8, 6, 94, 3, -10, 0};
    create(arr, 7);
    int c = count(first);
    printf("Number of nodes are : %d\n", c);
    c = Rcount(first);
    printf("Number of nodes are : %d\n", c);
}