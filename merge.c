#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
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

void Rdisplay(node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
}

void merge(node *p, node *q)
{
    node *last;
    if (p->data < q->data)
    {
        third = p;
        last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int main()
{
    int A[] = {5, 8, 9, 94, 158, 865, 8465};
    create(A, 7, &first);
    int B[] = {7, 15, 85, 89};
    create(B, 4, &second);
    merge(first, second);
    Rdisplay(third);
    printf("\n");
    return 0;
}