//#define DEBUG 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "BiTree.h"

//����ǰ�����˳�������������ɶ���������EMPTY_TREE��Ϊ���������ݱ�־��
int createBiTree(Node **T){
	ElemType data;
	scanf("%d",&data);
	
	if(data == EMPTY_TREE){
		//����
		*T = NULL;
	}else{
		*T = (Node *)malloc(sizeof(Node));
		if(!*T){
			//����ڴ������Ƿ�ɹ�
			puts("[RUN_ERROR]Malloc function Faild.\n");
			exit(RUN_ERROR);
		}
		//��ʼ�����
		memset(*T,0,sizeof(Node));
		//�����ݴ�����
		(*T)->element = data;

		//�ݹ鴴����������������
		createBiTree(&((*T)->lChild));
		createBiTree(&((*T)->rChild));
		
		#ifdef DEBUG
		printf("(*T) = %p	(*T)->element = %d	(*T)->lChild = %p	(*T)->rChild = %p\n",*T,(*T)->element,(*T)->lChild,(*T)->rChild );
		#endif
	}
	return 0;
}

//���ٶ��������ͷ��ڴ� 
void freeBiTree(Node *T){
	if(T->lChild){
		freeBiTree(T->lChild);
	}
	if(T->rChild){
		freeBiTree(T->rChild);
	}
	free(T);
}

//��ӡ���
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
//ǰ�����
void PreOrder(Node *T){
	if(T != NULL){
		if(printNode(T) != RUN_OK){
			puts("SORRY, printNode ERROR.\n");
		}
		PreOrder(T->lChild);
		PreOrder(T->rChild);
	}
}
//�������
void InOrder(Node *T){
	if(T != NULL){
		InOrder(T->lChild);
		if(printNode(T) != RUN_OK){
			puts("SORRY, printNode ERROR.\n");
		}
		PreOrder(T->rChild);
	}
}
//�������
void PostOrder(Node *T){
	if(T != NULL){
		PostOrder(T->lChild);
		PostOrder(T->rChild);
		if(printNode(T) != RUN_OK){
			puts("SORRY, printNode ERROR.\n");
		}
	}
}

//�������п鲢��ʼ��
Queue *createQueue(){
	Queue *sq = (Queue *)malloc(sizeof(Queue));
	memset(sq,0,sizeof(Queue));
	return sq;
}
//�������
//����ʹ�����鵥����ʵ�֣���ƶ��п飩��֧�ֶ�̬�ڴ���䣬������������������󡣰��������SQ_MAXSIZE���Ż��������ܡ�
void LevelOrder(Node *T){
	if(T != NULL){
		#ifdef DEBUG
		puts("LevelOrder START.\n");
		#endif
		Queue *sq = createQueue();  //β���п�
		Queue *sqf = sq;  //ͷ���п�
		Queue *tmp;  //���¶��п�ָ���õ���ʱָ��
		int front=0, rear=0;  //����ͷβָ��

		printf("%d ",T->element);  //��ӡ����
		//�������������
		sqf->NodeQ[rear++] = T->lChild;
		sqf->NodeQ[rear++] = T->rChild;

		Node *frontNode;  //����ͷ���ָ��
		while(/*front<rear*/1){
			frontNode = sqf->NodeQ[(front++)%SQ_MAXSIZE];  //�����У�����ͷָ��ǰ��
			printf("%d ",frontNode->element);  //�����ݲ���ӡ
			
			if(front%SQ_MAXSIZE==0){
				//��ȡ������һ���п飬����ǰ���п��ָ��������µĶ��п飬�ͷ���һ���п���ڴ档
				tmp = sqf->NextQ;
				free(sqf);
				sqf = tmp;
			}

			if(front==rear){
				//����Ϊ�գ���ȡ��ϡ��˳�ѭ����
				break;
			}

			//�жϵ�ǰ����Ƿ�ΪҶ�ӽ�㣬��������ӽ�����ӽ�������
			if(frontNode->lChild){
				sq->NodeQ[(rear++)%SQ_MAXSIZE] = frontNode->lChild;  //�ӽ������У�����βָ��ǰ��
				if(rear%SQ_MAXSIZE==SQ_MAXSIZE-1){
					//�����ǰ���п������Ѵ������򴴽��µĶ��п�
					sq->NextQ = createQueue();  //�¶��п��ַ����ԭ���п�
					sq = sq->NextQ;  //����β���п�ָ��
				}
			}
			//ͬ��
			if(frontNode->rChild){
				sq->NodeQ[(rear++)%SQ_MAXSIZE] = frontNode->rChild;
				if(rear%SQ_MAXSIZE==SQ_MAXSIZE-1){
					sq->NextQ = createQueue();
					sq = sq->NextQ;
				}
			}
		}
		if(front%SQ_MAXSIZE)
			//����δ�ͷŵĶ��п顣�ͷ��ڴ��ֹ�ڴ�й©��
			free(sqf);
	}
}
