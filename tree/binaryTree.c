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

TreeNode *initTreeNode(ELIMENT_TYPE data)
{
  TreeNode *node = malloc(sizeof(TreeNode));
  node->data = data;
  node->lTag = LINK;
  node->rTag = LINK;
  node->lc = NULL;
  node->lc = NULL;
}

typedef struct myTree
{
  TreeNode *root;
} BinaryTree;

//初始化一棵空树
BinaryTree *initEmptyTree()
{
  BinaryTree *temp = malloc(sizeof(BinaryTree));
  temp->root = NULL;
  return temp;
}

//根据树的根节点销毁（子）树
void deleteTreeByRoot(TreeNode *root)
{
  if(root->lc != NULL)
    deleteTreeByRoot(root->lc);
  if(root->rc != NULL)
    deleteTreeByRoot(root->rc);
  free(root);
}

//销毁树
void deleteTree(BinaryTree *tree)
{
  deleteTreeByRoot(tree->root);
  free(tree);
}

//根据二叉树的先序序列生成子树,返回生成的子树的根节点
TreeNode *generateTree(char **list)
{
  if(**list == 0)
    return NULL;
  if(**list == '@')
  {
    *list = *list + 1;
    return NULL;
  }
  TreeNode *temp = initTreeNode(**list);
  *list = *list + 1;
  temp->lc = generateTree(list);
  temp->rc = generateTree(list);
  return temp;
}

//根据二叉树的先序序列生成二叉树
BinaryTree *initTree(char *list)
{
  if(*list == 0)
    return initEmptyTree();
  BinaryTree *tree = malloc(sizeof(BinaryTree));
  tree->root = generateTree(&list);
  return tree;
}

//根据二叉树的先序遍历打印二叉树（输入根节点，打印子树）
void printPreOrder(TreeNode *node)
{
  printf("%c", node->data);
  if(node->lc != NULL)
    printPreOrder(node->lc);
  if(node->rc != NULL)
    printPreOrder(node->rc);
}

//根据二叉树的中序遍历打印二叉树（输入根节点，打印子树）
void printInOrder(TreeNode *node)
{
  if(node->lc != NULL)
    printInOrder(node->lc);
  printf("%c", node->data);
  if(node->rc != NULL)
    printInOrder(node->rc);
}

//根据二叉树的后序遍历打印二叉树（输入根节点，打印子树）
void printPostOrder(TreeNode *node)
{
  if(node->lc != NULL)
    printPostOrder(node->lc);
  if(node->rc != NULL)
    printPostOrder(node->rc);
  printf("%c", node->data);
}

//打印二叉树，type指示打印方式，1：先序遍历；2：中序遍历；3：后序遍历
void printTree(BinaryTree *tree, int type)
{
  if(tree->root == NULL)
  {
    printf("The tree is empty\n");
    return;
  }
  switch (type)
  {
  case PRE_ORDER:
    printPreOrder(tree->root);
    break;
  
  case IN_ORDER:
    printInOrder(tree->root);
    break;
  
  case POST_ORDER:
    printPostOrder(tree->root);
    break;
  
  default:
    break;
  }
  printf("\n");
}

//以中序遍历的方式打印线索二叉树
void printThreadedTree(BinaryTree *tree)
{
  TreeNode *temp = tree->root;
  while(temp != NULL)
  {
    while(temp->lc != NULL && temp->lTag == LINK)
      temp = temp->lc;
    //temp = temp->rc;
    while (temp != NULL && temp->rTag == THREAD)
    {
      printf("%c", temp->data);
      temp = temp->rc;
    }
    if(temp != NULL)
    {
      printf("%c", temp->data);
      temp = temp->rc;
    }
  }
  printf("\n");
}

//将以node为根节点的子树中序线索化
void makeThreaded(TreeNode **preNode, TreeNode *node)
{
  if(node->lc != NULL)
    makeThreaded(preNode, node->lc); // 线索化左子树
  else
  {
    node->lTag = THREAD;
    node->lc = *preNode;
  }
  if(*preNode != NULL && (*preNode)->rc == NULL)
  {
    (*preNode)->rTag = THREAD;
    (*preNode)->rc = node;
  }
  *preNode = node;
  if(node->rc != NULL)
    makeThreaded(preNode, node->rc); //线索化右子树
  else
  {
    node->rTag = THREAD;
    node->rc = NULL;
  }
}

//为二叉树生成中序线索二叉树
void makeThreadedInOrderTree(BinaryTree *tree)
{
  TreeNode *preNode = NULL;
  if(tree->root == NULL)
    return;
  makeThreaded(&preNode, tree->root);
}

int main(int argc, char const *argv[])
{
  char *list = "ABC@@DE@G@@F@@@";
  BinaryTree *myTree = initTree(list);
  printTree(myTree, PRE_ORDER);
  printTree(myTree, IN_ORDER);
  printTree(myTree, POST_ORDER);
  makeThreadedInOrderTree(myTree);
  //printTree(myTree, IN_ORDER);
  printThreadedTree(myTree);
  return 0;
}
