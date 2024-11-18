#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
typedef struct Node node;

void create(node **p, int x)
{
    node *t, *last;
    t = (node *)malloc(sizeof(node));
    t->data = x;
    t->next = t;
    if (*p == NULL)
    {
        last = t;
        *p = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
    last->next = *p;
}

void display(node *p)
{
    if (p == NULL)
        return;
    else
    {
        do
        {
            printf("%d ", p->data);
            p = p->next;
        } while (p != head);
    }
    printf("\n");
}

int main()
{
    create(&head, 10);
    create(&head, 10);
    create(&head, 10);
    create(&head, 10);
    create(&head, 10);
    create(&head, 10);
    create(&head, 10);
    create(&head, 10);
    display(head);
}