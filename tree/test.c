#include <stdio.h>
#include "binaryTree.h"
#include "huffmanTree.h"

int main(int argc, char const *argv[])
{
  char *list = "ABC@@DE@G@@F@@@";
  TreeNode *temp;
  BinaryTree *newTree;
  HuffmanTree *huffTree;
  int w[4] = {7, 5, 2, 4};

  printf("--------test binary tree--------\n");

  BinaryTree *myTree = initTree(list);
  printf("%d\n", judgeThreadedTree(myTree));

  printTree(myTree, PRE_ORDER);
  printTree(myTree, IN_ORDER);
  printTree(myTree, POST_ORDER);

  if(find(myTree, 'U') == NULL)
    printf("Not Found\n");
  else
    printf("Found\n");

  printf("Number of leafs is %d\n", countLeaf(myTree));

  printf("Depth of tree is %d\n", getDepth(myTree));

  makeThreadedInOrderTree(myTree);
  printf("%d\n", judgeThreadedTree(myTree));

  printTree(myTree, PRE_ORDER);
  printTree(myTree, IN_ORDER);
  printTree(myTree, POST_ORDER);

  if((temp = find(myTree, 'G')) == NULL)
    printf("Not found\n");
  else
  {
    printf("Found\n");
    printf("Pre node is %c\n", findPreNode(temp)->data);
    printf("Next node is %c\n", findNextNode(temp)->data);
  }

  newTree = makeTree(myTree);
  printTree(newTree, IN_ORDER);

  printf("--------test huffman tree--------\n");

  huffTree = initHuffmanTree(4, w);
  printHuffmanTree(huffTree);
  printf("With order--------\n");
  printHuffmanTreeInOrder(huffTree);

  return 0;
}