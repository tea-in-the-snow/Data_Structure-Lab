typedef struct huffNode
{
  int weight;
  int parent, lc, rc;
} HuffNode;

typedef struct huffmanTree
{
  int num;
  HuffNode *tree;
} HuffmanTree;

//创建Huffman树
HuffmanTree *initHuffmanTree(int num, int *weight);

//销毁Huffman树
void deleteHuffmanTree(HuffmanTree * tree);

//输出Huffman编码
//无顺序，dfs
void printHuffmanTree(HuffmanTree *tree);

//输出Huffman编码
//节点排序递减，bfs
void printHuffmanTreeInOrder(HuffmanTree *tree);