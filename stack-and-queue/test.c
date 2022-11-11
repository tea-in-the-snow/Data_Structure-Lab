#include <stdio.h>
#include "queue.h"
#include "stack.h"

int main(int argc, char const *argv[])
{
  Queue *queue;
  int flag, temp;

  queue = initQueue();
  pushQueue(queue, 1);
  pushQueue(queue, 2);
  pushQueue(queue, 3);
  pushQueue(queue, 4);
  temp = queueFront(queue, &flag);
  printf("head of the queue is %d\n", temp);
  printQueue(queue);
  popQueue(queue);
  printQueue(queue);
  pushQueue(queue, 6);
  pushQueue(queue, 7);
  printQueue(queue);
  popQueue(queue);
  popQueue(queue);
  popQueue(queue);
  printQueue(queue);

  Stack *stack;

  stack = initStack();
  pushStack(stack, 1);
  pushStack(stack, 2);
  pushStack(stack, 3);
  pushStack(stack, 4);
  pushStack(stack, 5);
  printStack(stack);
  popStack(stack);
  temp = stackTop(stack, &flag);
  printf("head of the queue is %d\n", temp);
  printStack(stack);
  popStack(stack);
  popStack(stack);
  printStack(stack);

  return 0;
}