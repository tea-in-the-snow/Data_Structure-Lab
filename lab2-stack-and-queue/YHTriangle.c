#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
#define MAX_LEVEL 15

typedef struct queue
{
  int front;
  int tail;
  int* q;
}Queue;

int nextPos(int x)
{
  return (x + 1) % MAX_QUEUE_SIZE;
}

//初始化队列
//注：front指向队头元素，tail指向队尾元素下一个元素
Queue* initQueue()
{
  Queue* queue;

  printf("initialize queue\n");
  queue = malloc(sizeof(Queue));
  queue->front = 0;
  queue->tail = 0;
  queue->q = malloc(sizeof(int) * (MAX_QUEUE_SIZE + 1));
  return queue;
}

void deleteQueue(Queue* queue)
{
  free(queue->q);
  free(queue);
}

// int empty(Queue* queue)
// {
//   if(queue->front == queue->tail)
//     return 1;
//   return 0;
// }

//出队
int pop(Queue* queue)
{
  //printf("queue pop\n");
  if(queue->front == queue->tail)
    return 1;
  queue->front = nextPos(queue->front);
}

//入队
int push(Queue* queue, int data)
{
  //printf("queue push %d\n", data);
  if(queue->front == nextPos(queue->tail)) {
    return 1;
  }
  *(queue->q + queue->tail) = data;
  queue->tail = nextPos(queue->tail);
  return 0;
}

//返回队头元素,flag = 1表示队列为空，= 0表示正常
int queueFront(Queue* queue, int* flag)
{
  if(queue->front == queue->tail) {
    *flag = 1;
    return 0;
  }
  *flag = 0;
  return *(queue->q + queue->front);
}

//打印队列中的元素
void printQueue(Queue* queue)
{
  int temp;

  if(queue->front == queue->tail)
    printf("queue is empty\n");
  temp = queue->front;
  while(temp != queue->tail) {
    printf("%d ", *(queue->q + temp));
    temp = nextPos(temp);
  }
  printf("\n");
}

void printYHTriangle(int level)
{
  Queue* queue;
  int presentLevel, temp, front, flag, next;

  //初始化操作
  queue = initQueue();
  presentLevel = 0;
  flag = 0;
  //第一层入队，-1，0分别指示层头层尾
  push(queue, -1);
  push(queue, 1);
  //push(queue, 0);
  temp = 0;
  //打印
  while(presentLevel <= level) {
    front = queueFront(queue, &flag);

    // printf("###");
    // printQueue(queue);
    // printf("temp=%d front=%d\n", temp, front);

    if(flag)
      break;
    pop(queue);
    next = temp + front;
    if(front == -1) {
      temp = 0;
      presentLevel++;
      push(queue, 0);
    }
    else if (front == 0) {
      printf("\n");
    }
    if(front > 0) {
      printf("%d ", front);
    }
    temp = front;
    if(temp == -1)
      temp = 0;
    push(queue, next);
  }
  deleteQueue(queue);
}

int main(int argc, char const *argv[])
{
  int level;

  if(argc != 2) {
    printf("Usage: YHTriangle <level>\n");
    return 1;
  }

  level = atoi(argv[1]);
  if(level <= 0) {
    printf("illeagl argumunt\n");
    return 1;
  }
  if(level > MAX_LEVEL) {
    printf("level can not be greater than %d\n", MAX_LEVEL);
    return 1;
  }

  printYHTriangle(level);

  return 0;
}
