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

void Linsert(node *p, int x)
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

void sort(node*p){
    node *q;
    while(p!=NULL){
        q= p->next;
        while(q!=NULL){
            if(p->data>q->data){
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            else
                q = q->next;
        }
        p = p->next;
    }
}

int main()
{
    Linsert(first, 100);
    Linsert(first, 50);
    Linsert(first, 40);
    Linsert(first, 7);
    Linsert(first, 55);
    display(first);
    sort(first);
    display(first);
    printf("\n");
    return 0;
}