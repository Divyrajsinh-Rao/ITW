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

void create(int x)
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

int main()
{
    create(10);
    create(10);
    create(10);
    create(10);
    create(10);
    create(10);
    display(first);
    return 0;
}