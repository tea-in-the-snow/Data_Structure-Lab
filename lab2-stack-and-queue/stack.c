#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node* next;
}Node;

typedef struct stack
{
  Node* top;
  int size;
}Stack;

Stack* initStack()
{
  Stack* newStack;

  printf("initialize stack\n");
  newStack = malloc(sizeof(Stack));
  newStack->top = NULL;
  newStack->size = 0;
  return newStack;
}

//出栈，成功返回0，空栈返回1
int pop(Stack* stack)
{
  Node* temp;

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
int push(Stack* stack, int data)
{
  Node* temp;

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

void deleteStack(Stack* stack)
{
  Node* temp;

  while(!pop(stack))
    ;
  free(stack);
  printf("stack deleted\n");
}

void printStack(Stack* stack)
{
  Node* temp;

  temp = stack->top;
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  Stack* stack;

  stack = initStack();
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);
  printStack(stack);
  pop(stack);
  printStack(stack);
  pop(stack);
  pop(stack);
  printStack(stack);
  
  return 0;
}

