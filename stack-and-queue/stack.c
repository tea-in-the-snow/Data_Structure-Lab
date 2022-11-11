#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *initStack()
{
  Stack *newStack;

  printf("initialize stack\n");
  newStack = malloc(sizeof(Stack));
  newStack->top = NULL;
  newStack->size = 0;
  return newStack;
}

//出栈，成功返回0，空栈返回1
int popStack(Stack *stack)
{
  Node *temp;

  printf("stask pop\n");
  if(stack->size == 0)
    return 1;
  temp = stack->top;
  stack->top = temp->next;
  stack->size--;
  free(temp);
  return 0;
}

//入栈，成功返回0，失败返回1
int pushStack(Stack *stack, stackData data)
{
  Node *temp;

  printf("stack push %d\n", data);
  temp = malloc(sizeof(Node));
  if(temp == NULL)
    return 1;
  temp->data = data;
  temp->next = stack->top;
  stack->top = temp;
  stack->size++;
  return 0;
}

//返回栈顶元素，flag = 1表示栈为空，= 0表示正常
int stackTop(Stack *stack, int *flag)
{
  if(stack->size == 0) {
    *flag = 1;
    return 0;
  }
  *flag = 0;
  return stack->top->data;
}

void deleteStack(Stack *stack)
{
  Node *temp;

  while(!popStack(stack))
    ;
  free(stack);
  printf("stack deleted\n");
}

void printStack(Stack *stack)
{
  Node *temp;

  temp = stack->top;
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

