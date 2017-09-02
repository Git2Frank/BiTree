/*
18.Traversal of Binary Tree 二叉数的遍历
v 1.3.3
LICENSE:  AGPL-3.0
*/
//#define DEBUG 
#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

//1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 -1 -1 

int main(int argc, char *argv[]) {
	puts("=============================");
	puts("  Traversal of Binary Tree");
	puts("- - - - - - - - - - - - - - -");
	puts("  Version	1.3.2\n  Author	iFrank\n  License	AGPL-3.0");
	puts("=============================\n");
	puts("Please enter your binary tree data in PREORDER to continue. \nDon't forget empty tree flag.\n");

	Node *T;  //二叉树树根结点指针
	if(createBiTree(&T) == RUN_ERROR){
		return RUN_ERROR;
	}
	puts("OK, GET IT.");
	
	puts("\nPreOrder:");
	PreOrder(T);

	puts("\n\nInOrder:");
	InOrder(T);

	puts("\n\nPostOrder:");
	PostOrder(T);

	puts("\n\nLevelOrder:");
	LevelOrder(T);
	
	freeBiTree(T);

	puts("\n\nAll done. Pless press ENTER to Exit.");
	while (getchar() != '\n');
	while (getchar() != '\n');

	return 0;
}
