#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;
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

node *reverse(node *p)
{
    node *q = NULL, *r = NULL, *z = p;
    while (z != NULL)
    {
        r = q;
        q = z;
        z = z->next;
        q->next = r;
    }
    p = q;
    return p;
}

int count(node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void Break(node *p)
{
    second = p->next;
    p->next = NULL;
}

node *middle(node *p)
{
    node *q = p;
    while (q != NULL)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    return p;
}

void create(node *p, int x)
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

bool isPalindrome(node *p)
{
    int c = count(p);
    node *q = middle(p);
    Break(q);
    node *r = reverse(second);
    if (c % 2 == 0)
    {
        while (p && r)
        {
            if (p->data != r->data)
                return false;
            p = p->next;
            r = r->next;
        }
        return true;
    }
    else
    {
        while (p->next && r)
        {
            if (p->data != r->data)
                return false;
            p = p->next;
            r = r->next;
        }
        return true;
    }
}

int main()
{
    create(first, 50);
    create(first, 40);
    create(first, 30);
    create(first, 20);
    create(first, 30);
    create(first, 40);
    create(first, 50);
    display(first);
    bool x = isPalindrome(first);
    if (x)
        printf("YES");
    else
        printf("NO");
    return 0;
}