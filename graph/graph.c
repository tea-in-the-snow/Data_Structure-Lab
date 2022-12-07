#ifndef __SOMEFILE_H__
#define __SOMEFILE_H__

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

#endif

// 新建一个只有顶点，没有边的图
Graph *initGraph(int vertexNum, ElementType *v)
{
  Graph *newGraph = malloc(sizeof(Graph));
  newGraph->vertexNum = vertexNum;
  newGraph->vertex = malloc(sizeof(GraphNode) * vertexNum);
  for(int i = 0; i < vertexNum; ++i)
  {
    newGraph->vertex[i].val = v[i];
    newGraph->vertex[i].adj = NULL;
  }
  return newGraph;
}

// 在图中添加有向边
int addEdge(Graph *graph, int src, int dest, int cost)
{
  if(graph->vertexNum < src || graph->vertexNum < cost)
    return 1;
  Edge *newEdge = malloc(sizeof(Edge));
  newEdge->cost = cost;
  newEdge->dest = dest;
  newEdge->link = NULL;
  GraphNode *v = graph->vertex + src;
  if(v->adj == NULL)
    v->adj = newEdge;
  else
  {
    Edge *temp = v->adj;
    while(temp->link != NULL)
      temp = temp->link;
    temp->link = newEdge;
  }
  return 0;
}

// 在图中添加无向边
int addUndirEdge(Graph *graph, int src, int dest, int cost)
{
  return addEdge(graph, src, dest, cost) || addEdge(graph, dest, src, cost);
}

// 打印图
void printGraph(Graph *graph)
{
  for(int i = 0; i < graph->vertexNum; ++i)
  {
    printf("Vertex : %d %c\n", i, graph->vertex[i].val);
    Edge *temp = graph->vertex[i].adj;
    while(temp != NULL)
    {
      printf("-- edge :%c -> %c %d\n", graph->vertex[i].val, graph->vertex[temp->dest].val, temp->cost);
      temp = temp->link;
    }
  }
}