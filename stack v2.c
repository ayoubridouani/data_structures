#include <stdio.h>
#include <stdlib.h>

int top = -1;

typedef struct STACK{
	int value;
	struct STACK *next;
}Stack;

void push(Stack**, int);
void pop(Stack**);
void print(Stack*);

int main(void){
	Stack *stack = NULL;

	push(&stack,10);
	push(&stack,20);
	push(&stack,30);
	push(&stack,40);
	push(&stack,50);
	print(stack);

	pop(&stack);
	print(stack);

	pop(&stack);
	print(stack);

	push(&stack,60);
	print(stack);

	return 0;
}

void push(Stack **p,int val){
	Stack *tmp_stack = (Stack*)malloc(sizeof(Stack));
	(*tmp_stack).value = val;
	(*tmp_stack).next = *p;
	*p = tmp_stack;
	++top;
}

void pop(Stack **p){
	if(*p == NULL ){
		printf("stack is empty");
	}else{
		Stack *tmp_stack = NULL;
		tmp_stack = *p;
		*p = (*p)->next;
		free(tmp_stack);
		--top;
	}
}

void print(Stack *p){
	for(int i=0;i<=top;i++){
		printf("%d ",(*p).value);
		p = (*p).next;
	}
	printf("\n");
}
