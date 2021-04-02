//gcc -o list list.c
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    Node *pre;
    Node *next;
    void *data;
};

bool is_equal_int(void *a, void *b)
{
    int a_tmp, b_tmp;
    if (!a || !b)
    {
        return false;
    }
    a_tmp = *(int *)a;
    b_tmp = *(int *)b;
    return a_tmp == b_tmp ? true : false;
}

void node_free(Node *node)
{
    if (!node)
    {
        return;
    }
    free(node->data);
    free(node);
}

Node *node_new(int data)
{
    Node *node = calloc(1, sizeof(Node));
    if (node)
    {
        int *data_ptr = calloc(1, sizeof(int));
        if (data_ptr)
        {
            *data_ptr = data;
            node->data = data_ptr;
        }
        else
        {
            free(node);
            node = NULL;
        }
    }
    return node;
}

//尾插法
Node *list_add(Node *head, Node *to_add)
{
    if (head == NULL)
    {
        to_add->next = NULL;
        to_add->pre = NULL;
        head = to_add;
    }
    else
    {
        Node *tmp = head;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        to_add->next = NULL;
        to_add->pre = tmp;
        tmp->next = to_add;
    }

    return head;
}

Node *list_delete(Node *head, void *data, bool (*is_equal)(void *a, void *b))
{
    Node *tmp = NULL;
    Node *new_head = head;
    if (!data)
    {
        return NULL;
    }
    tmp = head;
    while (tmp)
    {
        if (is_equal(tmp->data, data))
        {
            if (tmp->pre)
                tmp->pre->next = tmp->next;
            else
                new_head = tmp->next;
            if (tmp->next)
                tmp->next->pre = tmp->pre;
            node_free(tmp);
        }
        tmp = tmp->next;
    }
    return new_head;
}

void print_data_int(void *d)
{
    if (d)
    {
        printf("%d\n", *(int *)d);
    }
}

void list_print(Node *head, void (*print_data)(void *d))
{
    while (head)
    {
        print_data(head->data);
        head = head->next;
    }
}

void list_free(Node *head)
{
    Node *tmp = head;
    while (tmp)
    {
        tmp = tmp->next;
        node_free(head);
    }
}

int main(void)
{
    Node *list = NULL;
    int data;
    //add
    Node *to_add = node_new(1);
    if (to_add)
        list = list_add(list, to_add);

    //print
    list_print(list, print_data_int);

    //add
    to_add = node_new(2);
    if (to_add)
    {
        list = list_add(list, to_add);
    }

    //print
    list_print(list, print_data_int);

    //delete
    data = 3;
    list = list_delete(list, &data, is_equal_int);

    //print
    list_print(list, print_data_int);

    //free
    list_free(list);
    return 0;
}
