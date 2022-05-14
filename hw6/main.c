#include <stdio.h>
#include <stdlib.h>

struct node {
    int Data;
    struct node* Next;
};
typedef struct node node_t;

node_t* allocate_node(int data) {
    node_t* head = (node_t*)calloc(0,sizeof(node_t));
    head->Data = data;
    head->Next = NULL;
    return head;
}

void show_list(node_t* head) {
    while (head) {
        printf("[%d]-> ", head->Data);
        head = head->Next;
    }
    printf("null\n");
}

node_t* append_node(node_t* head, int new_data) {
    node_t* new_node = allocate_node(new_data);
    if (head) {
        head->Next = new_node;
    }
    else head = new_node;
    return head;
}

void free_all_node(node_t* head) {
    while (head) {
        node_t* p = head;
        head = head->Next;
        printf("free([%d])-> ", p->Data);
        free(p);
    }
    printf("null\n");
}

node_t* add_node(node_t* head, int new_data) {
    node_t* add_head = allocate_node(new_data);
    add_head->Next = head;
    return add_head;
}

node_t* del_node(node_t* head, int n) {
    if (n == 0) {
        node_t* next = head->Next;
        while (head->Next)
        {
            head->Data = next->Data;
            head->Next = next->Next;
            head = next;
        }
        return head;
    }
    node_t* p = head;
    node_t* previous_node = head;
    for (int num = 0; num < n; num++)
    {
        p = p->Next;
    }
    while (previous_node->Next != p)
    {
        previous_node = previous_node->Next;
    }
    previous_node->Next = p->Next;
    free(p);
    return previous_node;
}

int main()
{
    node_t* head = NULL;
    head = append_node(head,0);
    show_list(head);
    head = append_node(head,1);
    show_list(head);
    head = add_node(head, -1);
    show_list(head);
    del_node(head,2);
    show_list(head);
    free_all_node(head);
    return 0;
}
