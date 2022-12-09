#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
	char Element[MAX];
	int top;
}Stack;

void stackInit(Stack* pstack);
int isFull(Stack* pstack);
int isEmpty(Stack* pstack);
void push(Stack* pstack, int element);
int pop(Stack* pstack);
int checkMatching(char* exp);

int main() {
	char exp[MAX];

	while (1) {
		printf("string ют╥б(q = exit): ");
		fgets(exp, sizeof(exp), stdin);
		if (exp[0] == 'q')
			break;
		if (checkMatching(exp) == 1)
			puts("The string is balanced.\n");
		else
			puts("The string is unbalanced.\n");
	}
	
	return 0;
}

void stackInit(Stack* pstack) {
	pstack->top = -1;
}

int isFull(Stack* pstack) {
	return pstack->top == MAX - 1;
}

int isEmpty(Stack* pstack) {
	return pstack->top == -1;
}

void push(Stack* pstack, int element) {
	if (isFull(pstack)) {
		fprintf(stderr, "Stack is full!\n");
		return;
	}
	pstack->Element[++(pstack->top)] = element;
}

int pop(Stack* pstack) {
	if (isEmpty(pstack)) {
		fprintf(stderr, "Stack is empty!\n");
		exit(1);
	}
	return pstack->Element[(pstack->top)--];
}

int checkMatching(char* exp) {
	Stack stack;
	char ch, openCh;
	
	stackInit(&stack);

	for (int i = 0; i < strlen(exp); i++) {
		ch = exp[i];
		switch (ch) {
		case '(':
		case '{':
		case '[':
			push(&stack, ch);
			break;
		case ')':
		case '}':
		case ']':
			if (isEmpty(&stack))
				return 0;
			else {
				openCh = pop(&stack);
				if ((openCh == '(' && ch != ')') || (openCh == '{' && ch != '}') || (openCh == '[' && ch != ']'))
					return 0;
			}
			break;
		}
	}
	if (!isEmpty(&stack))
		return 0;

	return 1;
}