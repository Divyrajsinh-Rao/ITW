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

void delete(node *p, int pos)
{
    int x;
    node *q=NULL;
    if (pos < 1 || pos > count(p))
        return;
    else
    {
        if (pos == 1)
        {
            x = p->data;
            while (p->next != head)
                p = p->next;
            if (p == head)
            {
                free(head);
                head = NULL;
            }
            else
            {
                p->next = head->next;
                free(head);
                head = p->next;
            }
        }
        else
        {
            for (int i = 0; i < pos - 2; i++)
                p = p->next;
            q = p->next;
            x = q->data;
            p->next = q->next;
            free(q);
        }
    }
}

int main()
{
    int arr[] = {5615, 5, 4, 6, 4, 2, 4, 5, 4, 5, 8, 4};
    create(arr, 12, &head);
    delete (head, 12);
    display(head);
}