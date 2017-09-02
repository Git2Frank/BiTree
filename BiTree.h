#define EMPTY_TREE (-1) //空树标识
#define SQ_MAXSIZE 32 //队列数组大小
/*ERROR CODE*/
#define RUN_OK 1
#define RUN_ERROR 2

//节点数据类型，可以根据需要修改。不过还需手动修改scanf和printf里的占位符。
typedef int ElemType ;  
//二叉树结点
typedef struct TreeNode{
	ElemType element;
	struct TreeNode *lChild;
	struct TreeNode *rChild;
}Node;
//链式队列 用于层序遍历
typedef struct Queue{
	Node *NodeQ[SQ_MAXSIZE];
	struct Queue *NextQ;  //指向下一队列块的指针
}Queue;

//函数声明
int createBiTree(Node **);
void freeBiTree(Node *T);
int printNode(Node *);
void PreOrder(Node *);
void InOrder(Node *);
void PostOrder(Node *);
void LevelOrder(Node *);
Queue *createQueue();
