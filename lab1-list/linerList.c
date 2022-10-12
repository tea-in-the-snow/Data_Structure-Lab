#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

struct LinerList {
    int *data;
    int length;
};

typedef struct LinerList linerList;

//新建表
void newList(linerList *tmp) {
    tmp->data = (int*) malloc(MaxSize * sizeof(int));  //分配存储空间
    //如果空间分配失败
    if(tmp->data == NULL) {
        printf("memory error\n");
        exit(1);
    }
    tmp->length = 0;
    return;
}

//注销表，释放内存
void freeList(linerList *tmp) {
    free(tmp->data);
}

//添加元素
int addToTail(linerList *tmp, int x) {
    if(tmp->length > MaxSize) {
        return 0;
    }
    //在尾部添加
    tmp->data[tmp->length] = x;
    tmp->length++;
    return 1;
}

//插入元素
int insert(linerList *tmp, int x, int pos) {
    int i;
    //判断插入位置的合法性
    if(pos < 0 || pos > tmp->length || tmp->length >= MaxSize) {
        return 0;
    }
    //遍历到要插入的位置进行插入
    for(i = tmp->length; i > pos; --i) {
        tmp->data[i] = tmp->data[i - 1];
    }
    tmp->data[pos] = x;
    tmp->length++; 
    return 1;
}

//删除元素
int delete(linerList *tmp, int pos) {
    int i;
    //判断位置的合法性
    if(pos < 0 || tmp->length <= pos) {
        return 0;
    }
    for(i = pos; i < tmp->length - 1; ++i) {
        tmp->data[i] = tmp->data[i + 1];
    }
    tmp->length--;
    return 1;
}

//按序号查找元素：答案存在ans中，返回值表示是否查找成功
int selectByNumber(linerList *tmp, int pos, int* ans) {
    if(pos < 0 || tmp->length <= pos) {
        return 0;
    }
    *ans = tmp->data[pos];
    return 1;
}

//按值查找元素：-1表示找不到,否则返回所有满足条件的值中序号最小的值
int selectByValue(linerList *tmp, int value) {
    int i;
    //从头部开始遍历，知道找到满足条件的元素
    for(i = 0; i < tmp->length; ++i) {
        if(tmp->data[i] == value) {
            return i;
        }
    }
    return -1;
}

//倒序排列元素
void reverse(linerList *tmp) {
    int i, t;
    if(tmp->length <= 1) {
        return;
    }
    //交换数据域内容，不交换节点
    for(i = 0; i < tmp->length /2; ++i) {
        t = tmp->data[i];
        tmp->data[i] = tmp->data[tmp->length - i - 1];
        tmp->data[tmp->length - i - 1] = t;
    }
    return;
}

//按序输出元素
void print(linerList *tmp) {
    int i;
    for(i = 0; i < tmp->length; ++i) {
        printf("%d ", tmp->data[i]);
    }
    printf("\n");
    return;
}

int main()
{
    linerList tmp;
    int ans;
    printf("新建表\n");
    newList(&tmp);
    printf("在表的最后依次添加1,2,3,4\n");
    addToTail(&tmp, 1);
    addToTail(&tmp, 2);
    addToTail(&tmp, 3);
    addToTail(&tmp, 4);
    print(&tmp);
    printf("在位置为2处添加100\n");
    insert(&tmp, 100,2);
    print(&tmp);
    printf("输出值为100的元素的位置\n%d\n", selectByValue(&tmp, 100));
    printf("输出位置为2的元素的值\n");
    if(selectByNumber(&tmp, 2, &ans)) {
        printf("%d\n", ans);
    }
    printf("翻转表\n");
    reverse(&tmp);
    print(&tmp);
    printf("删除位置2的元素\n");
    delete(&tmp, 2);
    print(&tmp);
    freeList(&tmp);
    return 0;
}