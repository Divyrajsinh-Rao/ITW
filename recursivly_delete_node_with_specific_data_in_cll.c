// Write a recursive program for the deletion of all the nodes having specific data from the circular linked list.

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
    if (p == NULL)
        return;
    else
    {
        do
        {
            printf("%d ", p->data);
            p = p->next;
        } while (p != first);
    }
    printf("\n");
}

void delete(node *prev, node *curr, int x)
{
    int t;
    node *last = first;
    static int flag = 0;
    if (curr == NULL)
    {
        printf("NO NODE");
        return;
    }
    if (curr != first || flag == 0)
    {
        if (first->data == x)
        {
            flag = 0;
            while (last->next != first)
                last = last->next;
            if (last == first)
            {
                last->next = NULL;
                first = NULL;
            }
            first = curr->next;
            last->next = first;
            t = curr->data;
            free(curr);

            delete (NULL, last->next, x);
        }
        else if (curr->data == x)
        {
            prev->next = curr->next;
            t = curr->data;
            free(curr);
            delete (prev, prev->next, x);
        }

        else
        {
            flag = 1;
            delete (curr, curr->next, x);
        }
    }
    flag = 0;
}

void Linsert(node *p, int x)
{
    node *t, *last;
    t = (node *)malloc(sizeof(node));
    t->data = x;
    t->next = t;
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
    last->next = first;
}

int main()
{
    Linsert(first, 10);
    Linsert(first, 10);
    Linsert(first, 20);
    Linsert(first, 10);
    Linsert(first, 10);
    Linsert(first, 30);
    Linsert(first, 10);
    Linsert(first, 10);
    display(first);
    if (first == NULL)
        return 0;
    int x;
    printf("Enter the data you want to delete : ");
    scanf("%d", &x);
    delete (NULL, first, x);
    display(first);
    return 0;
}