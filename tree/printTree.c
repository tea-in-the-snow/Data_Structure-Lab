#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

//以中序遍历的方式打印根节点的线索二叉树子树
void printThreadedTreeInOrder(TreeNode *temp)
{
  while(temp != NULL)
  {
    while(temp->lc != NULL && temp->lTag == LINK)
      temp = temp->lc;
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
  int isThreadedTree = judgeThreadedTree(tree);
  if(tree->root == NULL)
  {
    printf("The tree is empty\n");
    return;
  }
  switch (type)
  {
  case PRE_ORDER:
    if(isThreadedTree)
    {
      printf("Do not support threaded tree");
      break;
    }
    printPreOrder(tree->root);
    break;
  
  case IN_ORDER:
    if(isThreadedTree)
      printThreadedTreeInOrder(tree->root);
    else
      printInOrder(tree->root);
    break;
  
  case POST_ORDER:
    if(isThreadedTree)
    {
      printf("Do not support threaded tree");
      break;
    }
    printPostOrder(tree->root);
    break;
  
  default:
    break;
  }
  printf("\n");
}