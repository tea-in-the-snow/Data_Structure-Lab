#include <stdlib.h>
#include <stdio.h>
#include "myMatrix.h"

MyMatrix *initMyMatrix(int line, int column, int elementNum, int *data)
{
  MyMatrix *matrix = malloc(sizeof(MyMatrix));
  matrix->column = column;
  matrix->line = line;
  matrix->elementNum = elementNum;
  matrix->data = malloc(sizeof(Triple) * elementNum);
  for(int i = 0; i < elementNum; ++i)
  {
    (matrix->data + i)->lineNum = data[i * 3];
    (matrix->data + i)->columnNum = data[i * 3 + 1];
    (matrix->data + i)->value = data[i * 3 + 2];
  }
  return matrix;
}

MyMatrix *initEmptyMyMatrix(int line, int column, int elementNum)
{
  MyMatrix *matrix = malloc(sizeof(MyMatrix));
  matrix->column = column;
  matrix->line = line;
  matrix->elementNum = elementNum;
  matrix->data = malloc(sizeof(Triple) * elementNum);
  return matrix;
}

void deleteMyMatrix(MyMatrix *matrix)
{
  free(matrix->data);
  free(matrix);
}

void printMyMatrix(MyMatrix *matrix)
{
  printf("--- matrix ---\n");
  printf("%d %d %d \n", matrix->line, matrix->column, matrix->elementNum);
  printf("------\n");
  for(int i = 0; i < matrix->elementNum; ++i)
  {
    printf("%d %d %d\n", (matrix->data + i)->lineNum, (matrix->data + i)->columnNum, (matrix->data + i)->value);
  }
  printf("--- matrix ---\n");
}

void transposeMyMatrix(MyMatrix *matrix, MyMatrix *newMatrix)
{
  newMatrix->column = matrix->line;
  newMatrix->line = matrix->column;
  newMatrix->elementNum = newMatrix->elementNum;
  Triple *temp;
  Triple *present;
  int pos = 0;
  for(int col = 0; col <= matrix->column; ++col)
  {
    for(int i = 0; i < matrix->elementNum; ++i)
    {
      temp = matrix->data + i;
      if(temp->columnNum == col)
      {
        present = newMatrix->data + pos;
        present->columnNum = temp->lineNum;
        present->lineNum = temp->columnNum;
        present->value = temp->value;
        pos++;
      }
    }
  }
}