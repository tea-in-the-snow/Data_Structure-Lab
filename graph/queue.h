#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue
{
  int front;
  int tail;
  int *q;
} Queue;

//初始化队列
//注：front指向队头元素，tail指向队尾元素下一个元素
Queue *initQueue();

void deleteQueue(Queue *queue);

//出队
int popQueue(Queue *queue);

//入队
int pushQueue(Queue *queue, int data);

//返回队头元素,flag = 1表示队列为空，= 0表示正常
int queueFront(Queue *queue, int *flag);

//打印队列中的元素
void printQueue(Queue *queue);

//队列为空返回1，否则返回0
int isQueueEmpty(Queue *queue);