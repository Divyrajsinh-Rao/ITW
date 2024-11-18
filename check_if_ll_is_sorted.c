#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

bool sorted(node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

int main()
{
    int arr[] = {10, 20, 30, 50, 80};
    create(arr, 5);
    bool z = sorted(first);
    if (z == true)
        printf("Sorted\n");
    else
        printf("Not sorted\n");
}