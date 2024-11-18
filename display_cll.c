// display circular linked list....

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
// or we can use this code to create a circular ll..

// void create(int A[], int n, node **q)
// {
//     node *p = NULL, *last = NULL;
//     *q = (node *)malloc(sizeof(node));
//     (*q)->data = A[0];
//     (*q)->next = *q;
//     last = *q;
//     for (int i = 1; i < n; i++)
//     {
//         p = (node *)malloc(sizeof(node));
//         p->data = A[i];
//         p->next = *q;
//         last->next = p;
//         last = p;
//     }
// }

void display(node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void Rdisplay(node*p){
    static int flag = 0;
    if(flag == 0 || p != head){
        flag = 1;
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
    flag = 0;
}

int main()
{
    int arr[] = {7, 5, 4, 6, 4, 2, 4, 5, 4, 5, 8, 4, 5, 7, 4};
    create(arr, 15, &head);
    display(head);
    Rdisplay(head);
}