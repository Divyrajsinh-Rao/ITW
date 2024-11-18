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

int count(node *p){
    int c = 0;
    do{
        c++;
        p = p->next;
    }while(p != head);
    return c;
}

int main()
{
    int arr[] = {7, 5, 4, 6, 4, 2, 4, 5, 4, 5, 8, 4};
    create(arr, 12, &head);
    display(head);
    printf("%d",count(head));
}