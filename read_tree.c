// Contains the function to read and construct the binary tree from the input file
// Output file: 1
// postorder traversal to preorder traversa

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


// @brief initialize the stack
Stack* CreateStack(int initialCapacity) {

	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->info = (Node**)malloc(sizeof(Node*) * initialCapacity);
	stack->top = -1;
	stack->capacity = initialCapacity;

	return stack;

}

// @brief Pop function for the stack
Node* Pop(Stack* stack) {

	if (stack->top == -1) {
		return NULL;
	}

	return stack->info[stack->top--];

}

// @brief Push function with dynamic resizing
void Push(Stack* stack, Node* node) {

	if (stack->top + 1 >= stack->capacity) {
		stack->capacity *= 2;
		Node** newInfo = (Node**)realloc(stack->info, sizeof(Node*) * stack->capacity);
		if (newInfo == NULL) {
			exit(EXIT_FAILURE);
		}
		stack->info = newInfo;
	}

	stack->info[++stack->top] = node;

}

// @brief Free the stack memory
void FreeStack(Stack* stack) {
	
	free(stack->info);
	free(stack);

}

// @brief create a new internal node
Node* CreateInternalNode(char cut, Node* left, Node* right) {

	Node* node = (Node*)malloc(sizeof(Node));
	node->isLeaf = 0;
	node->internal.cut = cut;
	node->internal.left = left;
	node->internal.right = right;

	return node;

}

// @brief create a new leaf node
Node* CreateLeafNode(int label, int width, int height) {

	Node* node = (Node*)malloc(sizeof(Node));
	node->isLeaf = 1;
	node->leaf.label = label;
	node->leaf.width = width;
	node->leaf.height = height;

	return node;

}

// @brief build the tree from postorder traversal using a stack
Node* BuildTreeFromPostorder(FILE* inputfile) {

	Stack* stack = CreateStack(10);

	char readline[256];
	while (fgets(readline, sizeof(readline), inputfile)) {
		if (readline[0] == 'H' || readline[0] == 'V') {
			Node* right = Pop(stack);
			Node* left = Pop(stack);
			Node* internalNode = CreateInternalNode(readline[0], left, right);
			Push(stack, internalNode);
		}
		else {
			int label, width, height;
			sscanf(readline, "%d(%d,%d)", &label, &width, &height);
			Node* leafNode = CreateLeafNode(label, width, height);
			Push(stack, leafNode);
		}
	}

	Node* rootNode = Pop(stack);
	FreeStack(stack);
	return rootNode;

}






/*
void PreorderTraversal(Node* node) {

	if (node == NULL) {
		return;
	}

	if (node->isLeaf) {
		printf("%d(%d,%d)\n", node->leaf.label, node->leaf.width, node->leaf.height);
	}
	else {
		print("%c", node->internal.cut);
	}

	PreorderTraversal(node->internal.left);
	PreorderTraversal(node->internal.right);

}*/