#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int Max(node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int RMax(node *p)
{
    int x = 0;
    if (p == 0)
        return INT_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

int Min(node *p)
{
    int min = INT_MAX;
    while (p)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}

int RMin(node *p)
{
    int x = 0;
    if (p == 0)
        return INT_MAX;
    x = RMin(p->next);
    if (p->data > x)
        return x;
    else
        return p->data;
}

int main()
{
    int arr[] = {5, 8, 6, 94, 3, -10, 0};
    create(arr, 7);
    int max = Max(first);
    printf("Maximum element is : %d\n", max);
    max = RMax(first);
    printf("Maximum element is : %d\n", max);
    int min = Min(first);
    printf("Minimum element is : %d\n", min);
    min = RMin(first);
    printf("Minimum element is : %d\n", min);
}