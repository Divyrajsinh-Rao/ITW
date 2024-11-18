// Write a C Program for merging two already sorted
// doubly circular linked lists into one sorted doubly circular linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;
typedef struct node node;

void create(node **p, int x)
{
    node *last, *t;
    t = (node *)malloc(sizeof(node));
    t->data = x;
    t->prev = NULL;
    t->next = NULL;
    if (*p == NULL)
    {
        *p = last = t;
    }
    else
    {
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void merge(node *p, node *q)
{
    node *last = NULL;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        p->prev = NULL;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        q->prev = NULL;
        last->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            p->prev = last;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            q->prev = last;
            last = q;
            q = q->next;
            last->next = NULL;
        }
        if(p)
            p->prev = NULL;
        if(q)
            q->prev = NULL;
    }
    if (p)
    {
        last->next = p;
        p->prev = last;
    }
    if (q)
    {
        last->next = q;
        q->prev = last;
    }
}

void display(node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    create(&first, 10);
    create(&first, 20);
    create(&first, 30);
    create(&first, 40);
    create(&first, 50);
    create(&first, 60);
    printf("First linked list : ");
    display(first);
    create(&second, 10);
    create(&second, 20);
    create(&second, 30);
    create(&second, 40);
    create(&second, 50);
    create(&second, 60);
    create(&second, 65);
    printf("Second linked list : ");
    display(second);
    merge(first, second);
    printf("Merged linked list : ");
    display(third);
}