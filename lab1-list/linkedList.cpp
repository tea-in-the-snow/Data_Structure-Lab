#include <iostream>

using namespace std;

struct node{
    int data;
    node * next;
};

//链表类，一个对象对应一个链表
class LinkedList {

private:
    node * head;

public:
    //初始化链表
    LinkedList() {
        head = new node;
        head->next = NULL;
    }

    node * getHead() {
        return head;
    }

    void setHead(node * head) {
        this->head = head;
        return;
    }

    //销毁链表
    void deleteList() {
        node * pos = head->next;
        head->next = NULL;
        //释放内存
        while(pos != NULL) {
            node * tmp = pos->next;
            delete pos;
            pos = tmp;
        }
    }

    //插入元素（头插法）
    void addToHead(int data) {
        node * newNode = new node;
        newNode->data = data;
        newNode->next = head->next;
        head->next = newNode;
    }

    //插入元素（尾插法）
    void addToTail(int data) {
        node * newNode = new node;
        newNode->data = data;
        newNode->next = NULL;
        node * pos = head->next;
        while(pos->next != NULL) {
            pos = pos->next;
        }
        pos->next = newNode;
    }

    //插入元素
    bool addToMiddle(int data, int position) {
        //判断要插入的位置是否合法
        if(position <= 0) {
            cout << "invalid position" <<endl;
            return false;
        }
        node * pos = head;
        int i = 1;
        while(pos->next != NULL && i < position) {
            pos = pos->next;
            i++;
        }
        //链表长度不够
        if(i != position) {
            cout << "position not exist" <<endl;
            return false;
        }
        //插入元素
        node * newNode = new node;
        newNode->data = data;
        newNode->next = pos->next;
        pos->next = newNode;
        return true;
    }

    //删除元素
    bool deleteNode(int position) {
        //判断要删除的序号是否合法
        if(position <= 0) {
            cout << "invalid position" <<endl;
            return false;
        }
        node * pos = head;
        int i = 1;
        while(pos->next != NULL && i < position) {
            pos = pos->next;
            i++;
        }
        if(i != position) {
            cout << "position not exist" <<endl;
            return false;
        }
        if(pos->next == NULL) {
            cout << "position not exist" <<endl;
            return false;
        }
        //删除节点
        node * tmp = pos->next;
        pos->next = tmp->next;
        delete tmp;
        return true;
    }

    //查找元素（按序号找）
    bool searchByNumber(int position, int * data) {
        //判断序号是否合法
        if(position <= 0) {
            cout << "invalid position" <<endl;
            return false;
        }
        node * pos = head;
        int i = 1;
        while(pos->next != NULL && i < position) {
            pos = pos->next;
            i++;
        }
        if(i != position) {
            cout << "position not exist" <<endl;
            return false;
        }
        if(pos->next == NULL) {
            cout << "position not exist" <<endl;
            return false;
        }
        *data = pos->next->data;
        return true;
    }

    //查找元素（按值找）
    bool find(int data, int * ans) {
        if(head->next == NULL) {
            cout << "not exist" << endl;
            return false;
        }
        int i = 1;
        node * pos = head->next;
        while(pos != NULL) {
            if(pos->data == data) {
                *ans = i;
                return true;
            }
            pos = pos->next;
            i++;
        }
        cout << "not exist" << endl;
        return false;
    }

    //倒序排列元素
    void reverse() {
        if(head->next == NULL) {
            return;
        }
        node * pos = head->next;
        node * tmp = pos->next;
        node * x;  //记录当前节点的下一个节点
        pos->next = NULL;
        while(tmp != NULL) {
            x = tmp->next;
            tmp->next = pos;
            pos = tmp;
            tmp = x;
        }
        head->next = pos;
        return;
    }

    //递增排序,使用插入排序，交换数据域
    void sort() {
        if(head->next == NULL) {
            return;
        }
        node * pos = head->next;
        node * minPos = pos;
        node * pointer = pos->next;
        while(pos != NULL) {
            int flag = pos->data;
            minPos = pos;
            pointer = pos->next;
            while(pointer != NULL) {
                if(pointer->data < flag) {
                    minPos = pointer;
                    flag = pointer->data;
                }
                pointer = pointer->next;
            }
            minPos->data = pos->data;
            pos->data = flag;
            pos = pos->next;
        }
        return;
    }

    //按序输出元素
    void print() {
        node * pos = head->next;
        while(pos != NULL) {
            cout << pos->data << " ";
            pos = pos->next;
        }
        cout << endl;
    }
};

void merge(LinkedList * a, LinkedList * b) {
    //将两个链表递增排序
    a->sort();
    b->sort();
    node * ans = new node;
    node * tmp = new node;
    node * posA = a->getHead()->next;
    node * posB = b->getHead()->next;
    //将两个链表当前节点中较小的节点添加到新链表的尾部
    while(posA != NULL || posB != NULL) {
        if(posA != NULL && posB != NULL) {
            if(posA->data < posB->data) {
                tmp = posA;
                posA = posA->next;
                tmp->next = ans->next;
                ans->next = tmp;
            }
            else {
                tmp = posB;
                posB = posB->next;
                tmp->next = ans->next;
                ans->next = tmp;
            }
        } else if(posA != NULL) {
            tmp = posA;
            posA = posA->next;
            tmp->next = ans->next;
            ans->next = tmp;
        } else if(posB != NULL) {
            tmp = posB;
            posB = posB->next;
            tmp->next = ans->next;
            ans->next = tmp;
        }
    }
    //将新链表链接到链表a的头节点
    a->getHead()->next = ans->next;
    return;
}

int main()
{
    int ans;
    LinkedList linkedList = LinkedList();
    cout << "依次在头部插入1,2,3,4\n";
    linkedList.addToHead(1);
    linkedList.addToHead(2);
    linkedList.addToHead(3);
    linkedList.addToHead(4);
    cout << "在尾部插入5\n";
    linkedList.addToTail(5);
    cout << "在位置2处插入100\n";
    linkedList.addToMiddle(100, 2);
    linkedList.print();
    cout << "输出位置2的节点\n";
    if(linkedList.searchByNumber(2, &ans)) {
        cout << ans << endl;
    }
    cout << "输出值为2的节点的位置\n";
    if(linkedList.find(2, &ans)) {
        cout << ans << endl;
    }
    cout << "删除位置2的节点\n";
    linkedList.deleteNode(2);
    linkedList.print();
    cout << "翻转链表（不使用额外空间）\n";
    linkedList.reverse();
    linkedList.print();
    cout << "排序\n";
    linkedList.sort();
    linkedList.print();
    cout << "新建链表如下:\n";
    LinkedList linkedListTwo =LinkedList();
    linkedListTwo.addToHead(6);
    linkedListTwo.addToHead(7);
    linkedListTwo.addToHead(8);
    linkedListTwo.addToHead(9);
    linkedListTwo.addToTail(10);
    linkedListTwo.print();
    cout << "对新链表和原链表执行merge方法\n";
    merge(&linkedList, &linkedListTwo);
    linkedList.print();
    return 0;
}