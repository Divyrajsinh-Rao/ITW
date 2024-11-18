// insert in circular ll..

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

typedef struct node node;

void create(int A[], int n, node **q)
{
    node *p = NULL, *last = NULL;
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
    last->next = *q;
}

void display(node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

void insert(node **p, int pos, int x)
{
    node *q = *p;
    node *t = (node *)malloc(sizeof(node));
    t->data = x;
    t->next = NULL;
    if (pos == 0)
    {
        
        if (*p == NULL){
            *p = t;
            t->next = *p;
        }
        else
        {
            while (q->next != *p)
                q = q->next;
            q->next = t;
            t->next = *p;
            *p = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            q = q->next;
        if (q)
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int arr[] = {7, 5, 4, 6, 4, 2, 4, 5, 4, 5, 8, 4, 5, 7, 4};
    create(arr, 15, &head);
    insert(&head, 0, 875);
    display(head);
}