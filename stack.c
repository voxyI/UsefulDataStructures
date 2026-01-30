#include "stack.h"

Stack* createStack() {
	Stack *s = (Stack *) malloc(sizeof(Stack));
	s->top = NULL;
	return s;
}

void push(Stack *s, int data) {
	_stack_node *n = (_stack_node *) malloc(sizeof(_stack_node));
	n->data = data;
	n->next = s->top;
	s->top = n;
}

int pop(Stack *s) {
	//assert s is not empty
	_stack_node *n = s->top;
	int data = n->data;
	s->top = n->next;
	free(n);
	return data;
}

bool isEmpty(Stack *s) {
	return s->top == NULL;
}

void freeStack(Stack **sPointer) {
	if(*sPointer == NULL) {
		return;
	}

	Stack *s = *sPointer;

	while(s->top != NULL) {
		_stack_node *n = s->top;
		s->top = n->next;
		free(n);
	}

	free(s);
	*sPointer = NULL;
}
