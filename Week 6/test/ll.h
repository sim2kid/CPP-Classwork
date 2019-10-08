#ifndef LL_H
#define LL_H

typedef struct node {
	int data;
	struct node * next;
} Node;

Node ** push(Node **, int);

#endif