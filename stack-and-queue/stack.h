#include <stdio.h>
#include <stdlib.h>

typedef int stackData;

typedef struct node
{
  stackData data;
  struct node *next;
}Node;

typedef struct stack
{
  Node *top;
  int size;
}Stack;

Stack *initStack();

//出栈，成功返回0，空栈返回1
int popStack(Stack *stack);

//入栈，成功返回0，失败返回1
int pushStack(Stack *stack, stackData data);

//返回栈顶元素，flag = 1表示栈为空，= 0表示正常
int stackTop(Stack *stack, int *flag);

void deleteStack(Stack *stack);

void printStack(Stack *stack);