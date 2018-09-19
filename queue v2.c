#include <stdio.h>
#include <stdlib.h>

int top = -1;

typedef struct QUEUE{
	int val;
	struct QUEUE *next;
}Queue;

void push(Queue**,int);
void pop(Queue*);
void print(Queue*);

int main(){
	Queue *queue = NULL;
	push(&queue,10);
	push(&queue,20);
	push(&queue,30);
	push(&queue,40);
	push(&queue,50);
	print(queue);

	pop(queue);
	print(queue);

	pop(queue);
	print(queue);

	push(&queue,60);
	print(queue);

	return 0;
}

void push(Queue **p,int val){
	Queue *tmp_queue = (Queue*)malloc(sizeof(Queue));
	(*tmp_queue).val = val;
	(*tmp_queue).next = *p;
	*p = tmp_queue;
	++top;
}

void pop(Queue* p){
	if(top == -1){
		printf("queue empty\n");
	}else{
		Queue *tmp_list = NULL;
		while(1){
			if(p->next == NULL) {
				if(tmp_list != NULL) tmp_list->next = NULL;
				break;
			}
			tmp_list = p;
			p = p->next;
		}
		free(p);
		--top;
	}
}

void print(Queue* q){
	for(int i=0;i<=top;i++){
		printf("%d ",q->val);
		q = q->next;
	}
	printf("\n");
}
