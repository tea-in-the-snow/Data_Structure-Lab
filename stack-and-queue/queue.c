#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int nextPos(int x)
{
  return (x + 1) % MAX_QUEUE_SIZE;
}

//初始化队列
//注：front指向队头元素，tail指向队尾元素下一个元素
Queue *initQueue()
{
  Queue *queue;

  printf("initialize queue\n");
  queue = malloc(sizeof(Queue));
  queue->front = 0;
  queue->tail = 0;
  queue->q = malloc(sizeof(int) * (MAX_QUEUE_SIZE + 1));
  return queue;
}

void deleteQueue(Queue *queue)
{
  free(queue->q);
  free(queue);
}

//出队
int popQueue(Queue *queue)
{
  printf("queue pop\n");
  if (queue->front == queue->tail)
    return 1;
  queue->front = nextPos(queue->front);
}

//入队
int pushQueue(Queue *queue, int data)
{
  printf("queue push %d\n", data);
  if (queue->front == nextPos(queue->tail))
  {
    return 1;
  }
  *(queue->q + queue->tail) = data;
  queue->tail = nextPos(queue->tail);
  return 0;
}

//返回队头元素,flag = 1表示队列为空，= 0表示正常
int queueFront(Queue *queue, int *flag)
{
  if (queue->front == queue->tail)
  {
    *flag = 1;
    return 0;
  }
  *flag = 0;
  return *(queue->q + queue->front);
}

//打印队列中的元素
void printQueue(Queue *queue)
{
  int temp;

  if (queue->front == queue->tail)
    printf("queue is empty\n");
  temp = queue->front;
  while (temp != queue->tail)
  {
    printf("%d ", *(queue->q + temp));
    temp = nextPos(temp);
  }
  printf("\n");
}
