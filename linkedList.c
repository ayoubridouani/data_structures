#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist *linked;

struct linkedlist{
	int  val;
	struct linkedlist *next;
};

//to create node
linked createNode(linked,int);

//to insert a node on the first of the list
void insert_node_in_beginning_list(linked*,int);

//to insert a node on the last of the list
void insert_node_in_end_List(linked*,int);

//to detele a node on the first of the list
void delete_node_in_Beginning_list(linked);

//to delete a node on the last of the list
void delete_node_in_end_list(linked*);

//to check if list is empty
short int is_empty_list(linked);

//to count how many list content of the node
int count_node_in_list(linked);

//to print all node in the list
void print(linked);

int main(void){

	linked list = NULL;

	list = createNode(list,1);
	list = createNode(list,2);
	list = createNode(list,3);
	list = createNode(list,4);
	print(list);

	insert_node_in_beginning_list(&list,0);
	print(list);

	insert_node_in_end_List(&list,5);
	print(list);

	delete_node_in_Beginning_list(list);
	print(list);

	delete_node_in_end_list(&list);
	print(list);

	return 0;
}

linked createNode(linked list,int x){
	linked node;
	node = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	node->val = x;
	node->next = list;
	return node;
}

void insert_node_in_beginning_list(linked *list,int x){
	if(!is_empty_list(*list)){
		*list = createNode(NULL,x);
	}else{
		linked tmp_list = *list;
		while(1){
			if((*list)->next == NULL){
				(*list)->next = createNode(NULL,x);
				break;
			}
			*list = (*list)->next;
		}
		*list = tmp_list;
	}
}

void insert_node_in_end_List(linked* list,int x){
	*list  = createNode(*list,x);
}

void delete_node_in_Beginning_list(linked list){
	if(!is_empty_list(list)){
		printf("delete_node_in_Beginning_list: linked list empty\n");
	}else{
		linked tmp_list = NULL;
		while(1){
			if(list->next == NULL) {
				if(tmp_list != NULL) tmp_list->next = NULL;
				break;
			}
			tmp_list = list;
			list = list->next;
		}
		free(list);
	}
}

void delete_node_in_end_list(linked* list){
	if(!is_empty_list(*list)){
		printf("delete_node_in_end_list: linked list empty\n");
	}else{
		linked tmp_list = (*list)->next;
		free(*list);
		*list = tmp_list;
	}
}

int count_node_in_list(linked list){
	int counter = 0;
	while(list!= NULL){
		counter++;
		list = list->next;
	}
	return counter;
}

short int is_empty_list(linked list){
	if(list == NULL) return 0;
	return 1;
}

void print(linked list){
	if(!is_empty_list(list)){
		printf("linked list empty\n");
	}else{
		while(list != NULL){
			printf("%d ",list->val);
			list = list->next;
		}
		printf("\n");
	}
}
