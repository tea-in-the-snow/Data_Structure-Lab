#include <stdio.h>
#include "myString.h"

int main(int argc, char const *argv[])
{
  MyString *str = initString("test string\n");
  printString(str);
  replace(str, "string", "str");
  printString(str);
  replace(str, "est", "esting");
  printString(str);
  deleteString(str);
  str = initString("ababcabcacbab");
  MyString *pattern = initString("abcac");
  printKmpNext(str, pattern);
  printf("test find : %d\n", find(str, pattern));
  printf("test kmp : %d\n", kmp(str, pattern));
  deleteString(str);
  return 0;
}
