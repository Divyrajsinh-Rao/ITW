#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
typedef struct Node node;

void display(node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void create(node *p, int x)
{
    node *t, *last;
    t = (node *)malloc(sizeof(node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        last = t;
        first = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

node *middle(node *p)
{
    node *q = p;
    while (q != NULL)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    return p;
}

int main()
{
    create(first, 10);
    create(first, 10);
    create(first, 30);
    create(first, 20);
    create(first, 40);
    create(first, 10);
    display(first);
    node *p = middle(first);
    printf("%d", p->data);
    return 0;
}