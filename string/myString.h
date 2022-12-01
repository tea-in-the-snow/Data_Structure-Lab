typedef struct myString
{
  char *str;
  int size;
} MyString;

// 初始化字符串
MyString *initString(char *str);

// 销毁字符串
void deleteString(MyString *str);

// 打印字符串
void printString(MyString *str);

// 搜索是否含有子串temp，若含有子串temp，返回1，用s替换temp，若不含有temp，返回0
int replace(MyString *str, char *temp, char *s);

// 目标串S和模式串T，匹配失败返回-1，匹配成功返回匹配位置
int find(MyString *str, MyString *pattern);

// kmp 算法，目标串S和模式串T，匹配失败返回-1，匹配成功返回匹配位置
int kmp(MyString *str, MyString *pattern);

// 打印 next 数组
void printKmpNext(MyString *str, MyString *pattern);