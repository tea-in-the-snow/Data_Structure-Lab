#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "queue.h"
#include "stack.h"

void dfs(Graph *graph, int *visited, int start)
{
  Stack *stack = initStack();
  pushStack(stack, start);
  visited[start] = 1;
  printf("%c", graph->vertex[start].val);
  int flag;
  while(!isStackEmpty(stack))
  {
    GraphNode temp = graph->vertex[stackTop(stack, &flag)];
    popStack(stack);
    Edge *edge = temp.adj;
    while(edge != NULL)
    {
      if(!visited[edge->dest])
      {
        pushStack(stack, edge->dest);
        visited[edge->dest] = 1;
        printf("%c", graph->vertex[edge->dest].val);
      }
      edge = edge->link;
    }
  }
}

void bfs(Graph *graph, int *visited, int start)
{
  Queue *queue = initQueue();
  pushQueue(queue, start);
  visited[start] = 1;
  printf("%c", graph->vertex[start].val);
  int flag;
  while(!isQueueEmpty(queue))
  {
    GraphNode temp = graph->vertex[queueFront(queue, &flag)];
    popQueue(queue);
    Edge *edge = temp.adj;
    while(edge != NULL)
    {
      if(!visited[edge->dest])
      {
        pushQueue(queue, edge->dest);
        visited[edge->dest] = 1;
        printf("%c", graph->vertex[edge->dest].val);
      }
      edge = edge->link;
    }
  }
}

void printConnected(Graph *graph)
{
  int num = graph->vertexNum;
  int visited[num];

  for(int i = 0; i < num; ++i)
    visited[i] = 0;
  printf("----- BFS conected components -----\n");
  for(int i = 0; i < num; ++i)
  {
    if(visited[i])
      continue;
    bfs(graph, visited, i);
    printf("\n");
  }
  printf("----- conected components -----\n");

  for(int i = 0; i < num; ++i)
    visited[i] = 0;
  printf("----- DFS conected components -----\n");
  for(int i = 0; i < num; ++i)
  {
    if(visited[i])
      continue;
    dfs(graph, visited, i);
    printf("\n");
  }
  printf("----- conected components -----\n");
}