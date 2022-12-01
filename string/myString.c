#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myString.h"

// 初始化字符串
MyString *initString(char *str)
{
  MyString *newStr = malloc(sizeof(MyString));
  newStr->size = strlen(str);
  newStr->str = malloc(sizeof(char) * (newStr->size + 1));
  strcpy(newStr->str, str);
  return newStr;
}

// 销毁字符串
void deleteString(MyString *str)
{
  free(str->str);
  free(str);
}

// 打印字符串
void printString(MyString *str)
{
  printf("%s\n", str->str);
}

// 搜索是否含有子串temp，若含有子串temp，返回1，用s替换temp，若不含有temp，返回0
int replace(MyString *str, char *temp, char *s)
{
  char *pos = strstr(str->str, temp);
  if (pos == NULL)
    return 0;
  str->size = str->size - strlen(temp) + strlen(s);
  char *newString = malloc(sizeof(char) * str->size + sizeof(char));
  char *newStr = newString;
  char *pointer;
  // 将要替换的子串之前的串复制到新的字符串中
  for (pointer = str->str; pointer != pos; ++pointer, ++newStr)
    *newStr = *pointer;
  // 将替换的子串复制到新的字符串中
  while (*s != 0)
  {
    *newStr = *s;
    ++s;
    ++newStr;
  }
  // 将要替换的子串之后的串复制到新的字符串中
  for (pointer += strlen(temp); *pointer != 0; ++pointer, ++newStr)
    *newStr = *pointer;
  *newStr = 0;

  free(str->str);
  str->str = newString;

  return 1;
}

int checkSame(char *a, char *b)
{
  while(*a == *b)
  {
    if(*a == 0)
      return 1;
    a++;
    b++;
  }
  if(*b == 0)
    return 1;
  return 0;
}

// 目标串S和模式串T，匹配失败返回-1，匹配成功返回匹配位置
int find(MyString *str, MyString *pattern)
{
  if (str->size < pattern->size || str->size == 0)
    return -1;
  for(int i = 0; i + pattern->size <= str->size; ++i)
  {
    if(checkSame(str->str + i, pattern->str))
      return i + 1;
  }
  return -1;
}

// kmp 算法，目标串S和模式串T，匹配失败返回-1，匹配成功返回匹配位置
int kmp(MyString *str, MyString *pattern)
{
  if (str->size < pattern->size || str->size == 0)
    return -1;
  int *next = malloc(sizeof(int) * pattern->size);
  //计算next数组的值
  next[0] = -1;
  for (int i = 1; i < pattern->size; ++i)
  {
    int k = i - 1;
    while (k > 0 && pattern->str[i - 1] != pattern->str[next[k]])
    {
      k = next[k];
    }
    next[i] = next[k] + 1;
  }
  //进行匹配
  int i = 0, j = 0;
  while (i < str->size)
  {
    while (i < str->size && str->str[i] == pattern->str[j])
    {
      i++;
      j++;
      if (j == pattern->size)
      {
        return i - j + 1;
      }
    }
    j = next[j];
    if (j < 0)
    {
      j = 0;
      i++;
    }
  }
  return -1;
}

// 打印 next 数组
void printKmpNext(MyString *str, MyString *pattern)
{
  if (str->size < pattern->size || str->size == 0)
  {
    printf("\n");
    return;
  }
  int *next = malloc(sizeof(int) * pattern->size);
  //计算next数组的值
  next[0] = -1;
  for (int i = 1; i < pattern->size; ++i)
  {
    int k = i - 1;
    while (k > 0 && pattern->str[i - 1] != pattern->str[next[k]])
    {
      k = next[k];
    }
    next[i] = next[k] + 1;
  }
  next[0] = 0;
  //打印
  for(int i = 0; i < pattern->size; ++i)
    printf("%d ", next[i]);
  printf("\n");
}