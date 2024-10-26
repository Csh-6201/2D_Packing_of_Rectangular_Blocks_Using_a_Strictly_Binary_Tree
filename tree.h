#ifndef tree_h
#define tree_h


typedef struct Node {
	int isLeaf;
	union {
		InternalNode internal;
		LeafNode leaf;
	};
}Node;

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


//Node* CreateInternalNode();

//void PreorderTraversal(Node* Node);


#endif