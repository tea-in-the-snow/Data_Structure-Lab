#include "binaryTree.h"

#define PRE 1
#define NEXT 0

//dfs，在root为根节点的子树中找值为v的节点
//普通二叉树
TreeNode *findInTree(TreeNode *root, char value)
{
  TreeNode *temp;
  if(root == NULL)
    return NULL;
  if(root->data == value)
    return root;
  if(root->lc != NULL)
    temp = findInTree(root->lc, value);
  if(temp != NULL)
    return temp;
  if(root->rc != NULL)
    temp = findInTree(root->rc, value);
  return temp;
}

//在root为根节点的子树中找值为v的节点
//线索二叉树
TreeNode *findInThreadedTree(TreeNode *temp, char value)
{
  while(temp != NULL)
  {
    while(temp->lc != NULL && temp->lTag == LINK)
      temp = temp->lc;
    while (temp != NULL && temp->rTag == THREAD)
    {
      if(temp->data == value)
        return temp;
      temp = temp->rc;
    }
    if(temp != NULL)
    {
      if(temp->data == value)
        return temp;
      temp = temp->rc;
    }
  }
  return NULL;
}

//定位二叉树中的节点，在树中找到值为v的节点则返回该节点，否则返回NULL
//支持普通二叉树与线索二叉树定位二叉树中的节点
TreeNode *find(BinaryTree *tree, char value)
{
  if(!judgeThreadedTree(tree))
    return findInTree(tree->root, value);
  else
    return findInThreadedTree(tree->root, value);
}

//计算以root为根节点的子树中叶子的数目
//仅支持普通二叉树
int countLeafInTree(TreeNode *root)
{
  if(root == NULL)
    return 0;
  if(root->lc == NULL && root->rc == NULL)
    return 1;
  return countLeafInTree(root->rc) + countLeafInTree(root->lc);
}

//计算二叉树的叶子结点数，仅支持普通二叉树，不考虑线索化
int countLeaf(BinaryTree *tree)
{
  return countLeafInTree(tree->root);
}

int max(int a, int b)
{
  if(a > b)
    return a;
  else
    return b;
}

//计算以root为根节点的子树的深度
//仅支持普通二叉树
int countDepth(TreeNode *root)
{
  if(root == NULL)
    return 0;
  return max(countDepth(root->lc), countDepth(root->rc)) + 1;
}

//计算二叉树的深度，仅支持普通二叉树，不考虑线索化
int getDepth(BinaryTree *tree)
{
  return(countDepth(tree->root));
}

//寻找中序线索二叉树中某节点的前驱或后继节点
//仅支持线索二叉树
TreeNode *findCloseNode(TreeNode *node, int type)
{
  if(node == NULL)
    return NULL;
  switch (type)
  {
  case PRE:
    return node->lc;
    break;
  
  case NEXT:
    return node->rc;
    break;
  
  default:
    break;
  }
}

//寻找中序线索二叉树中某节点的前驱节点，仅支持线索二叉树
//要求确保输入节点是中序线索二叉树中存在的节点
//不合法的输入返回空
TreeNode *findPreNode(TreeNode *node)
{
  return findCloseNode(node, PRE);
}

//寻找中序线索二叉树中某节点的后继节点，仅支持线索二叉树
//要求确保输入节点是中序线索二叉树中存在的节点
//不合法的输入返回空
TreeNode *findNextNode(TreeNode *node)
{
  return findCloseNode(node, NEXT);
}