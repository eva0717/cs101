#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int dataNum;
	struct node* next;
}node_t;

node_t* allocate_node(int data){
	int* ptr = (node_t*)calloc(1, sizeof(data));
	return ptr;
}

void show_list(node_t* list){
	
}

node_t* append_node(node_t* list, int new_data){
	if(list == NULL)allocate_node(new_data);
	node_t.dataNum = new_data;
	next = allocate_node(new_data);
}

void free_all_node(node_t* list){
	
}

int main(){
	node_t* head = NULL;
	head = append_node(head, 0);
	show_list(head);
	head = append_node(head, 11);
	show_list(head);
	head = append_node(head, 222);
	show_list(head);
	head = append_node(head, 3333);
	show_list(head);
	free_all_node(head);
}
