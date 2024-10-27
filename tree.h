#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct InternalNode {
	char cut;
	int height;
	int width;
	struct Node *left;
	struct Node *right;
}InternalNode;

typedef struct LeafNode {
	int label;
	int height;
	int width;
	int x;
	int y;
}LeafNode;

typedef struct Node {
	int isLeaf;
	union {
		InternalNode internal;
		LeafNode leaf;
	};
}Node;

typedef struct Stack {
	Node** info;
	int top;
	int capacity;
}Stack;

Stack* CreateStack(int initialCapacity);

Node* Pop(Stack* stack);

void Push(Stack* stack, Node* node);

void FreeStack(Stack* stack);

Node* CreateInternalNode(char cut, Node* left, Node* right);

Node* CreateLeafNode(int label, int width, int height);

Node* BuildTreeFromPostorder(FILE* inputfile);

void PreorderTraversalToFile(Node* node, FILE* outputfile);

void FreeNode(Node* node);


#endif