// insert in sorted circular ll....

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
    printf("\n");
}

int count(node *p)
{
    int c = 0;
    do
    {
        c++;
        p = p->next;
    } while (p != head);
    return c;
}

void Sinsert(node *p, int x)
{
    node *t;
    t = (node *)malloc(sizeof(node));
    t->data = x;
    t->next = NULL;
    node *q = NULL;

    if (head == NULL)
    {
        head = t;
        head->next = head;
    }
    else
    {
        while (p != NULL && p->data < x)
        {
            q = p;
            p = p->next;
            if (p == head && q != NULL)
                break;
        }
        if (p == head && q == NULL)
        {
            t->next = head;
            while (p->next != head)
                p = p->next;
            p->next = t;
            head = t;
        }
        else
        {
            q->next = t;
            t->next = p;
        }
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    create(arr, 10, &head);
    Sinsert(head, 0);
    display(head);
}