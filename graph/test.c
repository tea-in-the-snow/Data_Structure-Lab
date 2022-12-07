#ifndef __SOMEFILE_H__
#define __SOMEFILE_H__

#include <stdio.h>
#include "graph.h"
#include "solutions.h"

#endif

int main(int argc, char const *argv[])
{
  char v[] = "ABCDEFGHIJKLMNO";
  Graph *graph = initGraph(15, v);
  addUndirEdge(graph, 0, 1, 1); // AB
  addUndirEdge(graph, 0, 2, 1); // AC
  addUndirEdge(graph, 0, 3, 1); // AD
  addUndirEdge(graph, 0, 4, 1); // AE
  addUndirEdge(graph, 1, 5, 1); // BF
  addUndirEdge(graph, 4, 5, 1); // EF
  addUndirEdge(graph, 4, 6, 1); // EG
  addUndirEdge(graph, 5, 6, 1); // FG
  addUndirEdge(graph, 7, 8, 1); // HI
  addUndirEdge(graph, 7, 9, 1); // HJ
  addUndirEdge(graph, 8, 9, 1); // IJ
  addUndirEdge(graph, 10, 11, 1); // KL
  addUndirEdge(graph, 10, 12, 1); // KM
  addUndirEdge(graph, 10, 13, 1); // KN
  addUndirEdge(graph, 11, 14, 1); // LO
  addUndirEdge(graph, 12, 14, 1); // MO
  
  printConnected(graph);
  char v2[] = "123456789";
  Graph *graph2 = initGraph(9, v2);
  addEdge(graph2, 0, 1, 6);
  addEdge(graph2, 0, 2, 4);
  addEdge(graph2, 0, 3, 5);
  addEdge(graph2, 1, 4, 1);
  addEdge(graph2, 2, 4, 1);
  addEdge(graph2, 3, 5, 2);
  addEdge(graph2, 4, 6, 9);
  addEdge(graph2, 4, 7, 7);
  addEdge(graph2, 5, 7, 4);
  addEdge(graph2, 6, 8, 2);
  addEdge(graph2, 7, 8, 3);
  printCriticalPath(graph2);

  return 0;
}
