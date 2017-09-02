//#define DEBUG 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "BiTree.h"

//按照前序遍历顺序输入数据生成二叉树。宏EMPTY_TREE作为空树的数据标志。
int createBiTree(Node **T){
	ElemType data;
	scanf("%d",&data);
	
	if(data == EMPTY_TREE){
		//空树
		*T = NULL;
	}else{
		*T = (Node *)malloc(sizeof(Node));
		if(!*T){
			//检测内存申请是否成功
			puts("[RUN_ERROR]Malloc function Faild.\n");
			exit(RUN_ERROR);
		}
		//初始化结点
		memset(*T,0,sizeof(Node));
		//将数据存入结点
		(*T)->element = data;

		//递归创建左子树和右子树
		createBiTree(&((*T)->lChild));
		createBiTree(&((*T)->rChild));
		
		#ifdef DEBUG
		printf("(*T) = %p	(*T)->element = %d	(*T)->lChild = %p	(*T)->rChild = %p\n",*T,(*T)->element,(*T)->lChild,(*T)->rChild );
		#endif
	}
	return 0;
}

//销毁二叉树，释放内存 
void freeBiTree(Node *T){
	if(T->lChild){
		freeBiTree(T->lChild);
	}
	if(T->rChild){
		freeBiTree(T->rChild);
	}
	free(T);
}

//打印结点
int printNode(Node *T){
	if(T->element != EMPTY_TREE){
		printf("%d ",T->element);
		return RUN_OK;
	}else{
		#ifdef DEBUG
		puts("T->element == EMPTY_TREE");
		#endif
		return RUN_ERROR;
	}
	return 0;
}
//前序遍历
void PreOrder(Node *T){
	if(T != NULL){
		if(printNode(T) != RUN_OK){
			puts("SORRY, printNode ERROR.\n");
		}
		PreOrder(T->lChild);
		PreOrder(T->rChild);
	}
}
//中序遍历
void InOrder(Node *T){
	if(T != NULL){
		InOrder(T->lChild);
		if(printNode(T) != RUN_OK){
			puts("SORRY, printNode ERROR.\n");
		}
		PreOrder(T->rChild);
	}
}
//后序遍历
void PostOrder(Node *T){
	if(T != NULL){
		PostOrder(T->lChild);
		PostOrder(T->rChild);
		if(printNode(T) != RUN_OK){
			puts("SORRY, printNode ERROR.\n");
		}
	}
}

//创建队列块并初始化
Queue *createQueue(){
	Queue *sq = (Queue *)malloc(sizeof(Queue));
	memset(sq,0,sizeof(Queue));
	return sq;
}
//层序遍历
//队列使用数组单链表实现（简称队列块），支持动态内存分配，满足更大数据量的需求。按需调整宏SQ_MAXSIZE可优化程序性能。
void LevelOrder(Node *T){
	if(T != NULL){
		#ifdef DEBUG
		puts("LevelOrder START.\n");
		#endif
		Queue *sq = createQueue();  //尾队列块
		Queue *sqf = sq;  //头队列块
		Queue *tmp;  //更新队列块指针用的临时指针
		int front=0, rear=0;  //队列头尾指针

		printf("%d ",T->element);  //打印数据
		//左右子树入队列
		sqf->NodeQ[rear++] = T->lChild;
		sqf->NodeQ[rear++] = T->rChild;

		Node *frontNode;  //队列头结点指针
		while(/*front<rear*/1){
			frontNode = sqf->NodeQ[(front++)%SQ_MAXSIZE];  //出队列，队列头指针前移
			printf("%d ",frontNode->element);  //读数据并打印
			
			if(front%SQ_MAXSIZE==0){
				//读取到了下一队列块，将当前队列块的指针更新至新的队列块，释放上一队列块的内存。
				tmp = sqf->NextQ;
				free(sqf);
				sqf = tmp;
			}

			if(front==rear){
				//队列为空，读取完毕。退出循环。
				break;
			}

			//判断当前结点是否为叶子结点，如果存在子结点则将子结点入队列
			if(frontNode->lChild){
				sq->NodeQ[(rear++)%SQ_MAXSIZE] = frontNode->lChild;  //子结点入队列，队列尾指针前移
				if(rear%SQ_MAXSIZE==SQ_MAXSIZE-1){
					//如果当前队列块数组已存满，则创建新的队列块
					sq->NextQ = createQueue();  //新队列块地址记入原队列块
					sq = sq->NextQ;  //更新尾队列块指针
				}
			}
			//同上
			if(frontNode->rChild){
				sq->NodeQ[(rear++)%SQ_MAXSIZE] = frontNode->rChild;
				if(rear%SQ_MAXSIZE==SQ_MAXSIZE-1){
					sq->NextQ = createQueue();
					sq = sq->NextQ;
				}
			}
		}
		if(front%SQ_MAXSIZE)
			//存在未释放的队列块。释放内存防止内存泄漏。
			free(sqf);
	}
}
