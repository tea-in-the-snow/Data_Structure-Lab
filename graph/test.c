#include <stdio.h>
#include "graph.h"
#include "connected.h"

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

  return 0;
}
