#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

TreeNode *initTreeNode(ELIMENT_TYPE data)
{
  TreeNode *node = malloc(sizeof(TreeNode));
  node->data = data;
  node->lTag = LINK;
  node->rTag = LINK;
  node->lc = NULL;
  node->lc = NULL;
}

//初始化一棵空树
BinaryTree *initEmptyTree()
{
  BinaryTree *temp = malloc(sizeof(BinaryTree));
  temp->root = NULL;
  return temp;
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

//判断是否为线索二叉树，是返回1，否返回0，空树返回0
int judgeThreadedTree(BinaryTree *tree)
{
  TreeNode *temp = tree->root;
  if(temp == NULL)
    return 0;
  while(temp->lTag == LINK && temp->rTag == LINK)
  {
    if(temp->lc != NULL)
      temp = temp->lc;
    else if(temp->rc != NULL)
      temp = temp->rc;
    else
      return 0;
  }
  return 1;
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

//根据线索树的根节点销毁（子）树
void deleteThreadedTreeByRoot(TreeNode *root)
{
  if(root->lTag == LINK)
    deleteTreeByRoot(root->lc);
  if(root->rTag == LINK)
    deleteTreeByRoot(root->rc);
  free(root);
}

//销毁树
void deleteTree(BinaryTree *tree)
{
  if(judgeThreadedTree(tree))
    deleteThreadedTreeByRoot(tree->root);
  else
    deleteTreeByRoot(tree->root);
  free(tree);
}

//根据另一棵二叉树（的根节点）生成子树,返回生成的子树的根节点
//支持线索二叉树，返回普通二叉树
TreeNode *generateTreeByTree(TreeNode *node)
{
  TreeNode *temp = malloc(sizeof(TreeNode));
  temp->data = node->data;
  temp->lTag = LINK;
  temp->rTag = LINK;
  if(node->lc != NULL && node->lTag == LINK)
    temp->lc = generateTreeByTree(node->lc);
  if(node->rc != NULL && node->rTag == LINK)
    temp->rc = generateTreeByTree(node->rc);
  return temp;
}

//复制构造函数
BinaryTree *makeTree(BinaryTree *tree)
{
  BinaryTree *newTree = malloc(sizeof(BinaryTree));
  newTree->root = generateTreeByTree(tree->root);
  return newTree;
}
