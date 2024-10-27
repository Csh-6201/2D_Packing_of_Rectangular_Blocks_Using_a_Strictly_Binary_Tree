#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	// program's name + 1 input + 3 output
	/*if (argc != 5) {
		return 1;
	}*/

	//FILE* inputfile = fopen("input.txt", "r");
	FILE* inputfile = fopen(argv[1], "r");
	if (inputfile == NULL) {
		return 1;
	}
	Node* root = BuildTreeFromPostorder(inputfile);
	fclose(inputfile);

	//FILE* outputfile1 = fopen("output1.txt", "w");
	FILE* outputfile1 = fopen(argv[2], "w");
	if (outputfile1 == NULL) {
		FreeNode(root);
		return 1;
	}
	PreorderTraversalToFile(root, outputfile1);
	fclose(outputfile1);

	FreeNode(root);

	return 0;

}