#include <stdio.h>
#include <stdlib.h>
#include "huffmanTree.h"
#include "queue.h"
#include "stack.h"

#define MAX 0x7fffffff

//获取最小的两个节点
void getMinPos(HuffNode *temp, int num, int *pos, int *pos2)
{
  int min = MAX, min1 = MAX, i;
  HuffNode *x;
  for(i = 0; i < num; ++i)
  {
    x = temp + i;
    if(x->parent != -1)
      continue;
    if(x->weight < min)
    {
      min1 = min;
      *pos2 = *pos;
      min = x->weight;
      *pos = i;
    }
    else if (x->weight < min1)
    {
      min1 = x->weight;
      *pos2 = i;
    }
  }
}

void print(HuffmanTree *tree)
{
  int i;
  HuffNode *temp;
  printf("******** Huffman Tree ********\n");
  for(i = 0; i < tree->num; ++i)
  {
    temp = tree->tree + i;
    printf("%d %d %d %d\n", temp->weight, temp->parent, temp->lc, temp->rc);
  }
  printf("******** Huffman Tree ********\n");
}

//创建Huffman树
//可以使用优先队列，待优化
HuffmanTree *initHuffmanTree(int num, int *weight)
{
  int i;
  int pos, pos2; //指示两个最小的节点
  int nodeNum = num; // 指示可用的节点数量
  HuffmanTree *temp = malloc(sizeof(HuffmanTree));
  temp->num = num * 2 - 1;
  temp->tree = malloc(sizeof(HuffNode) * (num * 2 - 1));
  for(i = 0; i < num * 2 - 1; ++i)
  {
    (temp->tree + i)->parent = -1;
    (temp->tree + i)->lc = -1;
    (temp->tree + i)->rc = -1;
  }
  for(i = 0; i < num; ++i)
  {
    (temp->tree + i)->weight = weight[i];
  }
  for(i = num; i < num * 2 - 1; ++i)
  {
    getMinPos(temp->tree, i, &pos, &pos2);
    (temp->tree + pos)->parent = i;
    (temp->tree + pos2)->parent = i;
    (temp->tree + i)->lc = pos;
    (temp->tree + i)->rc = pos2;
    (temp->tree + i)->weight = (temp->tree + pos)->weight + (temp->tree + pos2)->weight;
  }
  return temp;
}

//销毁Huffman树
void deleteHuffmanTree(HuffmanTree * tree)
{
  free(tree->tree);
  free(tree);
}

//输出子树中的Huffman码
void printHuffmanNumber(HuffNode *node, int root, char *code)
{
  int i = 0;
  if((node + root)->lc == -1 && (node + root)->rc == -1)
  {
    printf("%d: %s\n", (node + root)->weight, code);
  }
  if((node + root)->rc != -1)
  {
    while(code[i] != 0)
      ++i;
    code[i] = '1';
    code[i + 1] = 0;
    printHuffmanNumber(node, (node + root)->rc, code);
    code[i] = 0;
  }
  if((node + root)->lc != -1)
  {
    while(code[i] != 0)
      ++i;
    code[i] = '0';
    code[i + 1] = 0;
    printHuffmanNumber(node, (node + root)->lc, code);
    code[i] = 0;
  }
}

//输出Huffman编码
//无顺序，dfs
void printHuffmanTree(HuffmanTree *tree)
{
  int root, i;
  char *code = malloc(sizeof(char) * tree->num); // 实际应按照树的深度来分配空间
  code[0] = 0;
  for(i = 0; i < tree->num; ++i)
  {
    if((tree->tree + i)->parent == -1)
    {
      root = i;
      break;
    }
  }
  printHuffmanNumber(tree->tree, i, code);
}

//打印pos节点的Huffman编码
void printHuffNumber(HuffmanTree *tree, int pos)
{
  int p, temp = pos, flag;
  HuffNode *node = tree->tree;
  Stack *stack = initStack();
  while((p = (node + temp)->parent) != -1)
  {
    if((node + p)->lc == pos)
      pushStack(stack, 0);
    else
      pushStack(stack, 1);
    temp = p;
  }
  printf("%d: ", (node + pos)->weight);
  while(!isStackEmpty(stack))
  {
    printf("%d", stackTop(stack, &flag));
    popStack(stack);
  }
  printf("\n");
  deleteStack(stack);
}

//输出Huffman编码
//节点排序递减，bfs
void printHuffmanTreeInOrder(HuffmanTree *tree)
{
  int root, i;
  int flag;
  HuffNode *node = tree->tree;
  for(i = 0; i < tree->num; ++i)
  {
    if((tree->tree + i)->parent == -1)
    {
      root = i;
      break;
    }
  }
  Queue *queue = initQueue();
  pushQueue(queue, root);
  while(!isQueueEmpty(queue))
  {
    i = queueFront(queue, &flag);
    popQueue(queue);
    if((node + i)->lc == -1 && (node + i)->rc == -1)
      printHuffNumber(tree, i);
    if((node + i)->rc != -1)
      pushQueue(queue, (node + i)->rc);
    if((node + i)->lc != -1)
      pushQueue(queue, (node + i)->lc);
  }
  deleteQueue(queue);
}