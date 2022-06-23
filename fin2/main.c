#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
    char data;
    struct LinkedList *next;
} LinkedList;

LinkedList *alloNode(int data) {
    LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = data;
    node->next = NULL;
    return node;
}

void showList(LinkedList *head) { 
    LinkedList *temp = head;
    while (temp != NULL) {
        printf("[%c]->", temp->data);
        temp = temp->next;
    }
    printf("->NULL\n");
}

LinkedList *appendList(LinkedList *head, char val) {
    LinkedList *node = alloNode(val);
    node->data = val;
    node->next = NULL;
    if (head == NULL) {
        head = node;
    } 
    else{
        LinkedList *lastNode = head;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        } 
        lastNode->next = node;
    }
    return head;
}

LinkedList *reverseList(LinkedList *head) {
    LinkedList *prev = NULL;
    LinkedList *current = head;
    LinkedList *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    LinkedList* head = NULL;
    head = appendList(head, 'A');
    head = appendList(head, 'B');
    head = appendList(head, 'C');
    head = appendList(head, 'D');
    head = appendList(head, 'E');
    showList(head);
    head = reverseList(head);
    showList(head);
    return 0;
}
