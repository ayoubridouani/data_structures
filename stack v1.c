#include <stdio.h>
#include <stdlib.h>

#define size 100

struct STACK{
	int top;
	int items[size];
};

void push(struct STACK*, int);
void pop(struct STACK*);
void print(struct STACK);

int main(void){
	struct STACK Stack;
	Stack.top=-1;

	push(&Stack,10);
	push(&Stack,20);
	push(&Stack,30);
	push(&Stack,40);
	push(&Stack,50);
	print(Stack);

	pop(&Stack);
	print(Stack);

	return 0;
}

void push(struct STACK *Stack, int x){
	if(Stack->top+1 < size){
		Stack->top++;
		Stack->items[Stack->top]=x;
	}else{
		printf("stack satured\n");
	}
}

void pop(struct STACK *Stack){
	if(Stack->top == -1){
		printf("stack empty\n");
	}else{
		Stack->items[Stack->top]=0;
		Stack->top--;
	}
}

void print(struct STACK Stack){
	for(int i=0;i<=Stack.top;i++){
		printf("%d ",Stack.items[i]);
	}
	printf("\n");
}
