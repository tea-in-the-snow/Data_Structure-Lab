#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH  100

typedef int stackData;

typedef struct node
{
  stackData data;
  struct node *next;
} Node;

typedef struct stack
{
  Node *top;
  int size;
} Stack;

Stack *initStack()
{
  Stack *newStack;

  //printf("initialize stack\n");
  newStack = malloc(sizeof(Stack));
  newStack->top = NULL;
  newStack->size = 0;
  return newStack;
}

//出栈，成功返回0，空栈返回1
int pop(Stack *stack)
{
  Node *temp;

  //printf("stask pop\n");
  if (stack->size == 0)
    return 1;
  temp = stack->top;
  stack->top = temp->next;
  stack->size--;
  free(temp);
  return 0;
}

//入栈，成功返回0，失败返回1
int push(Stack *stack, stackData data)
{
  Node *temp;

  //printf("stack push %d\n", data);
  temp = malloc(sizeof(Node));
  if (temp == NULL)
    return 1;
  temp->data = data;
  temp->next = stack->top;
  stack->top = temp;
  stack->size++;
  return 0;
}

//返回栈顶元素，flag = 1表示栈为空，= 0表示正常
int stackTop(Stack *stack, int *flag)
{
  if (stack->size == 0)
  {
    *flag = 1;
    return 0;
  }
  *flag = 0;
  return stack->top->data;
}

void deleteStack(Stack *stack)
{
  Node *temp;

  while (!pop(stack))
    ;
  free(stack);
  printf("stack deleted\n");
}

void printStack(Stack *stack)
{
  Node *temp;

  temp = stack->top;
  while (temp != NULL)
  {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int priority(char x)
{
  if (x == '*' || x == '/')
    return 2;
  else if (x == '+' || x == '-')
    return 1;
  return 0;
}

//将前缀表达式exp转换为后缀表达式str
int change(const char *exp, char *str)
{
  Stack *signalSt;  //符号栈，用于转换为后缀表达式
  int pos, flag, strPos;
  char present, temp;

  pos = 0;
  strPos = 0;
  signalSt = initStack();
  while ((present = *(exp + pos)) != '\0')
  {
    //若为数字，直接输出
    if (isdigit(present))
    {
      *(str + strPos) = present;
      strPos++;
      *(str + strPos) = '\0';
    }
    //若为'(',直接入栈
    else if (present == '(')
    {
      push(signalSt, present);
    }
    //若为')',将符号栈中的元素依次出栈并输出,直到'(','('只出栈, 不输出
    else if (present == ')')
    {
      temp = stackTop(signalSt, &flag);
      while (!flag)
      {
        if(temp == '(')
        {
          pop(signalSt);
          break;
        }
        else
        {
          *(str + strPos) = temp;
          strPos++;
          *(str + strPos) = '\0';
          pop(signalSt);
        }
        temp = stackTop(signalSt, &flag);
      }
    }
    /*若为其他符号,将符号栈中的元素依次出栈并输出,
    直到遇到比当前符号优先级更低的符号或者'('。将当前符号入栈。
    扫描完后,将栈中剩余符号依次输出*/
    else
    {
      temp = stackTop(signalSt, &flag);
      while(!flag && priority(temp) >= priority(present))
      {
        pop(signalSt);
        *(str + strPos) = temp;
        strPos++;
        *(str + strPos) = '\0';
        temp = stackTop(signalSt, &flag);
      }
      push(signalSt, present);
    }
    pos++;
  }
  temp = stackTop(signalSt, &flag);
  while(!flag)
  {
    pop(signalSt);
    *(str + strPos) = temp;
    strPos++;
    *(str + strPos) = '\0';
    temp = stackTop(signalSt, &flag);
  }
  return 0;
}

//计算后缀表达式
int calculate(char *str)
{
  Stack *st;
  int pos, flag;
  char present, before, after;

  st = initStack();
  pos = 0;
  while((present = *(str + pos)) != '\0')
  {
    //若是数字直接入栈
    if(isdigit(present))
      push(st, present);
    //若是操作符弹出两个数字运算，结果入栈
    else if (present == '-')
    {
      after = stackTop(st, &flag);
      pop(st);
      before = stackTop(st, &flag);
      pop(st);
      push(st, before - after + '0');
    }
    else if (present == '+')
    {
      after = stackTop(st, &flag);
      pop(st);
      before = stackTop(st, &flag);
      pop(st);
      push(st, before + after - '0');
    }
    else if (present == '*')
    {
      after = stackTop(st, &flag);
      pop(st);
      before = stackTop(st, &flag);
      pop(st);
      push(st, (before - '0') * (after - '0') + '0');
    }
    else if (present == '/')
    {
      after = stackTop(st, &flag);
      pop(st);
      before = stackTop(st, &flag);
      pop(st);
      push(st, (before - '0') / (after - '0') + '0');
    }
    pos++;
  }
  return stackTop(st, &flag) - '0';
}

int main(int argc, char const *argv[])
{
  const char *tmp;
  char *str;

  if (argc != 2)
  {
    printf("Usage: calculate <expression>\n");
    return 1;
  }

  str = malloc(sizeof(char) * MAX_LENGTH);  //存放后缀表达式
  *str = '\0';
  tmp = argv[1];
  change(tmp, str);
  printf("后缀表达式为\"%s\"\n", str);
  printf("%s = %d\n", tmp, calculate(str));
  return 0;
}
