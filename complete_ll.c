#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *create_add_at_last(node *head, int x)
{
    node *new, *last;
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
        return NULL;
    new->data = x;
    new->next = NULL;
    if (head == NULL)
    {
        last = head = new;
    }
    else
    {
        last->next = new;
        last = new;
    }

    return head;
}
node *create_add_at_front(node *head, int x)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
        return NULL;
    new->data = x;
    new->next = NULL;
    if (head == NULL)
        head = new;
    else
    {
        new->next = head;
        head = new;
    }
    return head;
}

node *add_at_given_position(node *head, int x, int pos)
{
    if (pos < 1 || pos > count_number_of_nodes(head))
    {
        printf("Give correct position please!");
        return NULL;
    }
    node *temp = head, *new, *prev = NULL;
    new = (node *)malloc(sizeof(node));
    if (new == NULL)
        return NULL;
    new->data = x;
    new->next = NULL;
    if (pos == 1)
    {
        new->next = head;
        head = new;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = new;
        new->next = temp;
    }
    return head;
}

int count_number_of_nodes(node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int recursive_count_number_of_nodes(node *head)
{
    if (head != NULL)
        return 1 + recursive_count_number_of_nodes(head->next);
    else
        return 0;
}

void display(node *head)
{
    if (head == NULL)
        return;
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void recursive_display(node *head)
{
    if (head != NULL)
    {
        printf("%d ", head->data);
        recursive_display(head->next);
    }
    printf("\n");
}

node *delete_from_given_position(node *head, int pos)
{
    if (pos < 1 || pos > count_number_of_nodes(head))
    {
        printf("Give correct position please!");
        return NULL;
    }
    node *temp = head, *prev = NULL;
    if (pos == 1)
    {
        head = head->next;
        free(temp);
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp)
        {
            prev->next = temp->next;
            free(temp);
        }
    }
    return head;
}

node *delete_given_key(node *head, int key)
{
    node *temp = head, *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = temp->next;
                free(temp);
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

node *reverse(node *head)
{
    node *current = NULL, *prev = NULL, *temp = head;
    while (current != NULL)
    {
        prev = current;
        current = temp;
        temp = temp->next;
        current->next = prev;
    }
    head = current;
    return head;
}

node *recursive_reverse(node *head, node *current, node *prev)
{
    if (current)
    {
        recursive_reverse(head, current->next, current);
        current->next = prev;
    }
    else
        head = current;
    return head;
}

int find_max_element(node *head)
{
    int max = INT_MIN;
    while (head)
    {
        if (head->data > max)
            max = head->data;
        head = head->next;
    }
    return max;
}

int recursively_find_max_element(node *head)
{
    int max = INT_MIN;
    if (head == NULL)
        return max;
    max = recursively_find_max_element(head->next);
    if (max > head->data)
        return max;
    else
        return head->data;
}

int find_min_element(node *head)
{
    int min = INT_MAX;
    while (head)
    {
        if (head->data < min)
            min = head->data;
        head = head->next;
    }
    return min;
}

int recursively_find_min_element(node *head)
{
    int min = INT_MAX;
    if (head == NULL)
        return INT_MAX;
    min = recursively_find_min_element(head->next);
    if (min < head->data)
        return min;
    else
        return head->data;
}

node *merge_two_sorted_list(node *first, node *second, node *third)
{
    node *last, *temp1 = first, *temp2 = second;
    if (first->data < second->data)
    {
        last = third = first;
        temp1 = temp1->next;
        last->next = NULL;
    }
    else
    {
        last = third = second;
        temp2 = temp2->next;
        last->next = NULL;
    }
    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
        {
            last->next = temp1;
            last = temp1;
            temp1 = temp1->next;
            last->next = NULL;
        }
        else
        {
            last->next = temp2;
            last = temp2;
            temp2 = temp2->next;
            last->next = NULL;
        }
    }
    if (temp1)
        last->next = temp1;
    if (temp2)
        last->next = temp2;
    return third;
}

bool search_for_key(node *head, int key)
{
    if (head == NULL)
        return false;
    while (head)
    {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

bool recursivly_search_for_key(node *head, int key)
{
    if (head == NULL)
        return false;
    if (head->data == key)
        ;
    return true;
    recursivly_search_for_key(head->next, key);
}

node *remove_duplicates(node *head)
{
    if (head == NULL)
        return NULL;
    node *temp = head, *search, *prev;
    while (temp->next)
    {
        search = temp->next;
        prev = temp;
        while (search)
        {
            if (temp->data == search->data)
            {
                prev->next = search->next;
                free(search);
                search = prev->next;
            }
            else
            {
                prev = search;
                search = search->next;
            }
        }
        if (temp->next)
            temp = temp->next;
    }
    return head;
}

node *remove_duplicates_from_sorted_list(node *head)
{
    if (head == NULL)
        return NULL;
    node *current = head, *temp = current->next;
    while (current->next)
    {
        if (temp->data == current->data)
        {
            current->next = temp->next;
            free(temp);
            temp = current->next;
        }
        else
        {
            current = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    node *first = NULL, *second = NULL, *third = NULL;
}