typedef int ElemType;

typedef struct triple
{
  int lineNum;
  int columnNum;
  ElemType value;
} Triple;

typedef struct myMatrix
{
  int line;
  int column;
  int elementNum;
  Triple *data;
} MyMatrix;

MyMatrix *initMyMatrix(int line, int column, int elementNum, int *data);

MyMatrix *initEmptyMyMatrix(int line, int column, int elementNum);

void deleteMyMatrix(MyMatrix *matrix);

void printMyMatrix(MyMatrix *matrix);

void transposeMyMatrix(MyMatrix *matrix, MyMatrix *newMatrix);