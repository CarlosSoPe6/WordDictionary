/**
 * TDA Stack
 * Stack.h
 */

#include "Stack.h"
#include "Bool.h"
#include <stdlib.h>

struct strNode {
	Type data;
	struct strNode* prior;
};

typedef struct strNode* Node;

struct strStack {
	Node top;
	UInt size;
};

Stack stack_create() {
	Stack st = (Stack) malloc(sizeof(struct strStack));
	st->top  = NULL;
	st->size = 0;
	return st;
}

void  stack_push(Stack st, Type _data) {
	Node n   = (Node) malloc(sizeof(struct strNode));
	n->data  = _data;
	n->prior = st->top;
	st->top  = n;
	st->size ++;
}

Type  stack_pop(Stack st) {
	if(stack_isEmpty(st)) return NULL;

	Node n = st->top;
	Type d = n->data;
	st->top = n->prior;
	free(n);
	st->size --;
	return d;
}

Type  stack_top(Stack st) {
	if(stack_isEmpty(st))
		return NULL;
	else
		return st->top->data;
}

Bool  stack_isEmpty(Stack st) {
	return st->top == NULL;
}

UInt  stack_size(Stack st) {
	return st->size;
}

void  stack_destroy(Stack st) {
	if(!stack_isEmpty(st)) {
		Node current = st->top;
		Node _prior   = current->prior;
		while(_prior != NULL) {
			free(current);
			current = _prior;
			_prior  = _prior->prior;
		}
		free(current);
	}
	free(st);
}
