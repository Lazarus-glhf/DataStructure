/**
 * @file LinkList_WithHead.cpp
 * @author Lazarus
 * @brief 带头节点链表
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

#define ElemType int

/**
 * @brief 带头节点链表
 * 
 */
struct LNode
{
    ElemType data;
    LNode* next;
};

typedef LNode* LinkList;

/**
 * @brief 头插构建链表
 * 
 * @param l 
 * @return LinkList 
 */
LinkList List_HeadInsert(LinkList& l)
{
    LNode* s;
    int x;
    l = (LinkList)malloc(sizeof(LNode));
    l->next = nullptr;
    cin >> x;
    while(x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = l->next;
        l->next = s;
        cin >> x;
    }

    return l;
}

/**
 * @brief 尾插构建
 * 
 * @param l 
 * @return LinkList 
 */
LinkList List_EndInster(LinkList& l)
{
    LNode* s;
    LNode* flag;
    int x;

    l = new LNode;
    l->next = nullptr;
    flag = l;

    cin >> x;
    while (x != 9999)
    {
        s = new LNode;
        s->data = x;
        s->next = nullptr;
        flag->next = s;
        flag = s;
        cin >> x;
    }
    return l;
}

/**
 * @brief 按序插入算法
 * 
 * @param l LinkList
 * @param i location
 * @param data 
 * @return true 
 * @return false 
 */
bool ListInsert(LinkList& l, int i, ElemType data)
{
    if (i < 1) return false;

    LNode* p = l;
    int j = 0;

    while (p != nullptr && j < i - 1)
    {
        p = p->next;
        j++;
    }

    if (p == nullptr) return false;

    LNode* s = new LNode;
    s->data = data;
    s->next = p->next;
    p->next = s;

    return true;
}

int main()
{
    LinkList l;
    l = List_HeadInsert(l);
    LNode* s = l->next;
    while (s != nullptr)
    {
        cout << s->data << '\n';
        s = s->next;
    }

}
