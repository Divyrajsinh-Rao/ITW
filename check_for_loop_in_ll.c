#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

typedef struct Node node;

void create(int A[], int n, node **q)
{
    node *last = NULL, *p;
    *q = (node *)malloc(sizeof(node));
    (*q)->data = A[0];
    (*q)->next = NULL;
    last = *q;
    for (int i = 1; i < n; i++)
    {
        p = (node *)malloc(sizeof(node));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

bool loop(node *p)
{
    node *q = p;
    do
    {
        q = q->next;
        if (q)
            q = q->next;
        p = p->next;
    } while (p != q && p && q);
    
    if (p == q && p && q)
        return true;
    else
        return false;
}

int main()
{
    node *t1, *t2;
    int A[] = {1, 68, 44, 8, 35, 5, 1, 8, 78, 5, 8};
    create(A, 11, &first);
    t1 = first->next->next;
    t2 = first->next->next->next->next->next->next;
    t2->next = t1;
    bool x = loop(first);
    printf("%d", x);
}