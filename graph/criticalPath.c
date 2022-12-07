#ifndef __SOMEFILE_H__
#define __SOMEFILE_H__

#include <stdio.h>
#include "graph.h"
#include "solutions.h"

#endif

// 拓扑排序，成功返回0，若存在环，返回1
int topologicalSort(Graph *graph, int *topology)
{
  int inDeg[graph->vertexNum]; // 入度
  for (int i = 0; i < graph->vertexNum; ++i)
    inDeg[i] = 0;
  // 遍历每一条边计算入度
  for (int i = 0; i < graph->vertexNum; ++i)
  {
    Edge *edge = graph->vertex[i].adj;
    while (edge != NULL)
    {
      inDeg[edge->dest]++;
      edge = edge->link;
    }
  }
  int num = 0; // 当前已经排序好的节点个数
  int count = 0;
  while (num < graph->vertexNum)
  {
    for (int i = 0; i < graph->vertexNum; ++i)
    {
      if (inDeg[i] == 0)
      {
        topology[num++] = i; // 加入拓扑排序序列中
        // 从节点出发的所有边的下一个节点入度减一
        Edge *edge = graph->vertex[i].adj;
        while (edge != NULL)
        {
          inDeg[edge->dest]--;
          edge = edge->link;
        }
      }
    }
    if(count > graph->vertexNum)
      return 1;
    count++;
  }
  return 0;
}

void printCriticalPath(Graph *graph)
{
  int num = graph->vertexNum;
  int topo[num];
  if (topologicalSort(graph, topo))
  {
    printf("Critical path does not existed.\n");
    return;
  }

  int ve[num], vl[num];
  // 计算 ve
  for(int i = 0; i < num; ++i)
  {
    ve[i] = 0;
  }
  for(int i = 0; i < num; ++i)
  {
    Edge *edge = graph->vertex[i].adj;
    while (edge != NULL)
    {
      if(ve[i] + edge->cost > ve[edge->dest])
        ve[edge->dest] = ve[i] + edge->cost;
      edge = edge->link;
    }
  }
  // 计算 vl
  for(int i = 0; i < num; ++i)
  {
    vl[i] = ve[num - 1];
  }
  for(int i = num - 1; i >= 0; --i)
  {
    Edge *edge = graph->vertex[i].adj;
    while (edge != NULL)
    {
      if(vl[edge->dest] - edge->cost < vl[i])
        vl[i] = vl[edge->dest] - edge->cost;
      edge = edge->link;
    }
  }

  int e, l;
  for(int i = 0; i < num; ++i)
  {
    Edge *edge = graph->vertex[i].adj;
    while(edge != NULL)
    {
      e = ve[i];
      l = vl[edge->dest] - edge->cost;
      if(e == l)
        printf("Critical path : %c -> %c\n", graph->vertex[i].val, graph->vertex[edge->dest].val);
      edge = edge->link;
    }
  }
}