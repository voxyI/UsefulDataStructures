#ifndef _stack
#define _stack
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _stack_node{
	int data;
	struct _stack_node *next;
} _stack_node;

typedef struct Stack{
	_stack_node *top;
} Stack;

Stack* createStack();
void push(Stack *s, int data);
int pop(Stack *s);
bool isEmpty(Stack *s);
void freeStack(Stack **s);

#endif