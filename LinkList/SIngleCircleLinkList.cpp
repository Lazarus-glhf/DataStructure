#include <iostream>
using namespace std;
#define ElemType int

struct LNode
{
    ElemType data;
    LNode* next;
};
typedef LNode* LinkList;

/**
 * @brief 初始化循环链表 L
 */
bool InitList(LinkList &L)
{
    L = new LNode;
    if (L == nullptr) { return false; }
    L->next = L;

    return true;
}

/**
 * @brief 判断循环链表 L 是否为空
 */
bool Empty(LinkList L)
{
    if (L->next == L) { return true; }
    else return false;
}

/**
 * @brief 判断节点 p 是否为循环链表 L 的尾节点
 */
bool isTail(LinkList L, LNode* p)
{
    if (p->next == L) { return true; }
    else return false;
}


int main()
{

}