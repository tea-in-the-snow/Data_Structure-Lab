#include <stdio.h>
#include "myString.h"
#include "myMatrix.h"

int main(int argc, char const *argv[])
{
  printf("+++++ test string +++++\n");
  MyString *str = initString("test string");
  printString(str);
  replace(str, "string", "str");
  printString(str);
  replace(str, "est", "esting");
  printString(str);
  deleteString(str);
  str = initString("ababcabcacbab");
  MyString *pattern = initString("ababaaababaa");
  printKmpNext(str, pattern);
  printf("test find : %d\n", find(str, pattern));
  printf("test kmp : %d\n", kmp(str, pattern));
  deleteString(str);
  printf("+++++ test string +++++\n\n");
  printf("+++++ test matrix +++++\n");
  int data[9] = {1, 1, 20, 2, 1, 10, 13, 15, 100};
  MyMatrix *matrix = initMyMatrix(40, 50, 3, data);
  printMyMatrix(matrix);
  MyMatrix *newMatrix = initEmptyMyMatrix(50, 40, 3);
  transposeMyMatrix(matrix, newMatrix);
  printMyMatrix(newMatrix);
  printf("+++++ test matrix +++++\n");
  return 0;
}
