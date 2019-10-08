#ifndef LL_H
#define LL_H

typedef struct node {
	int data;
	struct node * next;
} Node;

void push(Node **, int);
void pop(Node **, int);
void print(Node *);
int has(Node **, int);

#endif