#include <stdio.h>
#include <stdlib.h>

#define LINK 0
#define THREAD 1
#define PRE_ORDER 1
#define IN_ORDER 2
#define POST_ORDER 3

typedef char ELIMENT_TYPE;

typedef struct treeNode
{
  ELIMENT_TYPE data;
  int lTag, rTag;
  struct treeNode *lc;
  struct treeNode *rc;
} TreeNode;

typedef struct myTree
{
  TreeNode *root;
} BinaryTree;

//initTree.c

TreeNode *initTreeNode(ELIMENT_TYPE data);

//初始化一棵空树
BinaryTree *initEmptyTree();

//根据二叉树的先序序列生成二叉树
BinaryTree *initTree(char *list);

//复制构造函数
BinaryTree *makeTree(BinaryTree *tree);

//为二叉树生成中序线索二叉树
void makeThreadedInOrderTree(BinaryTree *tree);

//判断是否为线索二叉树，是返回1，否返回0，空树返回0
int judgeThreadedTree(BinaryTree *tree);

//销毁树
void deleteTree(BinaryTree *tree);

//printTree.c

//打印二叉树，type指示打印方式，1：先序遍历；2：中序遍历；3：后序遍历
void printTree(BinaryTree *tree, int type);

//opsonTree.c

//定位二叉树中的节点，在树中找到值为v的节点则返回该节点，否则返回NULL
//支持普通二叉树与线索二叉树定位二叉树中的节点
TreeNode *find(BinaryTree *tree, char value);

//计算二叉树的叶子结点数，仅支持普通二叉树，不考虑线索化
int countLeaf(BinaryTree *tree);

//计算二叉树的深度，仅支持普通二叉树，不考虑线索化
int getDepth(BinaryTree *tree);

//寻找中序线索二叉树中某节点的前驱节点，仅支持线索二叉树
//要求确保输入节点是中序线索二叉树中存在的节点
//不合法的输入返回空
TreeNode *findPreNode(TreeNode *node);

//寻找中序线索二叉树中某节点的后继节点，仅支持线索二叉树
//要求确保输入节点是中序线索二叉树中存在的节点
//不合法的输入返回空
TreeNode *findNextNode(TreeNode *node);