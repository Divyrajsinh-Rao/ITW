#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *first = NULL;
typedef struct node node;

void create(node **p, int x){
    node *last, *t;
    t = (node*)malloc(sizeof(node));
    t->data = x;
    t->prev = NULL;
    t->next = NULL;
    if(*p == NULL){
        *p = last = t;
    }
    else{
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(node* p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    create(&first, 10);
    create(&first, 10);
    create(&first, 10);
    create(&first, 10);
    create(&first, 10);
    create(&first, 10);
    display(first);
}