typedef char ElementType;

typedef struct edge
{
  int dest;
  int cost;
  struct edge *link;
} Edge;

typedef struct graphNode
{
  ElementType val;
  Edge *adj;
} GraphNode;

typedef struct graph
{
  GraphNode *vertex;
  int vertexNum;
} Graph;

// 新建一个只有顶点，没有边的图
Graph *initGraph(int vertexNum, ElementType *v);

// 打印图
void printGraph(Graph *graph);

// 在图中添加有向边
int addEdge(Graph *graph, int src, int dest, int cost);

// 在图中添加无向边
int addUndirEdge(Graph *graph, int src, int dest, int cost);