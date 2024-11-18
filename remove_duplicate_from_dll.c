// remove duplicate from doubly ll....

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *first = NULL;
typedef struct node node;

void create(node **p, int A[], int n)
{
    node *t, *last = NULL;
    *p = (node *)malloc(sizeof(node));
    (*p)->data = A[0];
    (*p)->prev = NULL;
    (*p)->next = NULL;
    last = *p;

    for (int i = 1; i < n; i++)
    {
        t = (node *)malloc(sizeof(node));
        t->data = A[i];
        t->prev = last;
        last->next = t;
        t->next = NULL;
        last = t;
    }
}

void display(node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void duplicate(node *p)
{
    int x;
    node *q, *temp;
    while (p->next != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                x = q->data;
                if (q->next != NULL)
                {
                    q->prev->next = q->next;
                    q->next->prev = q->prev;
                }
                else
                {
                    q->prev->next = NULL;
                }
                temp = q;
                free(temp);
            }
            q = q->next;
        }
        if (p->next)
            p = p->next;
    }
}

int main()
{
    int A[] = {1, 84, 5, 8, 6, 1};
    create(&first, A, 6);
    duplicate(first);
    display(first);
}