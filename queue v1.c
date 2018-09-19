#include <stdio.h>
#include <stdlib.h>

#define size 100

struct QUEUE{
	int top;
	int items[size];
};

void push(struct QUEUE*, int);
void pop(struct QUEUE*);
void print(struct QUEUE);

int main(void){
	struct QUEUE Queue;
	Queue.top = -1;

	push(&Queue,10);
	push(&Queue,20);
	push(&Queue,30);
	push(&Queue,40);
	push(&Queue,50);
	print(Queue);

	pop(&Queue);
	print(Queue);

	return 0;
}

void push(struct QUEUE* queue, int x){
	if(queue->top+1 < size){
		queue->top++;
		queue->items[queue->top]=x;
	}else{
		printf("queue satured");
	}
}

void pop(struct QUEUE* queue){
	if(queue->top == -1){
		printf("Queue empty\n");
	}else{
		for(int i=0;i<queue->top;i++){
			queue->items[i] = queue->items[i+1];
		}
		queue->top--;
	}
}

void print(struct QUEUE queue){
	for(int i=0;i<=queue.top;i++){
		printf("%d ",queue.items[i]);
	}
	printf("\n");
}
