#define EMPTY_TREE (-1) //������ʶ
#define SQ_MAXSIZE 32 //���������С
/*ERROR CODE*/
#define RUN_OK 1
#define RUN_ERROR 2

//�ڵ��������ͣ����Ը�����Ҫ�޸ġ����������ֶ��޸�scanf��printf���ռλ����
typedef int ElemType ;  
//���������
typedef struct TreeNode{
	ElemType element;
	struct TreeNode *lChild;
	struct TreeNode *rChild;
}Node;
//��ʽ���� ���ڲ������
typedef struct Queue{
	Node *NodeQ[SQ_MAXSIZE];
	struct Queue *NextQ;  //ָ����һ���п��ָ��
}Queue;

//��������
int createBiTree(Node **);
void freeBiTree(Node *T);
int printNode(Node *);
void PreOrder(Node *);
void InOrder(Node *);
void PostOrder(Node *);
void LevelOrder(Node *);
Queue *createQueue();
