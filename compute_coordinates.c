// Contains the function to compute the coordinates of the rectangular blocks
// Output file: 3

#include "tree.h"


void FreeNode(Node* node) {

	if (node == NULL) {
		return;
	}

	if (!node->isLeaf) {
		FreeNode(node->internal.left);
		FreeNode(node->internal.right);
	}

	free(node);

}