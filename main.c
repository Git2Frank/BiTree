/*
18.Traversal of Binary Tree 
v 1.3.2
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
	puts("=============================");
	puts("Please enter your binary tree data in PREORDER to continue. Don't forget empty tree flag.");

	Node *T;  //二叉树树根结点指针
	if(createBiTree(&T) == RUN_ERROR){
		return RUN_ERROR;
	}
	puts("OK, GET IT.\n");
	while (getchar() != '\n');
	puts("Pless press ENTER to PreOrder.");
	while (getchar() != '\n');
	
	PreOrder(T);
	puts("\nPreOrder DONE.\n");
	puts("Pless press ENTER to InOrder.");
	while (getchar() != '\n');

	InOrder(T);
	puts("\nInOrder DONE.\n");
	puts("Pless press ENTER to PostOrder.");
	while (getchar() != '\n');
	
	PostOrder(T);
	puts("\nPostOrder DONE.\n");
	puts("Pless press ENTER to LevelOrder.");
	while (getchar() != '\n');

	LevelOrder(T);
	puts("\nLevelOrder DONE.\n");
	puts("Pless press ENTER to Exit.");
	while (getchar() != '\n');

	freeBiTree(T);
	return 0;
}
