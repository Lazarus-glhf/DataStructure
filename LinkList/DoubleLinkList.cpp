#include <iostream>
using namespace std;

#define Elemtype int

struct DLinkNode
{
    Elemtype data;
    DLinkNode* prior = nullptr;
    DLinkNode* next = nullptr;
};

typedef DLinkNode*  DLinkList;

bool InitDLinkList(DLinkList& L)
{
    L = new DLinkNode;
    if (L == nullptr)  return false;
    L->data = 0;
    L->prior = nullptr;
    L->next = nullptr;

    return true;
}

bool Empty(const DLinkList& L)
{
    if (L->next == nullptr) { return true; }

    else { return false; }
}

/**
 * @brief 将 S 插入到 P 后
 * 
 * @param p 双链表节点 p
 * @param s 双链表节点 s
 * @return true 
 * @return false 
 */
bool InsertNextNode(DLinkNode *p, DLinkNode *s)
{
    if (p == nullptr || s == nullptr) { return false; }

    s->next = p->next;
    if (p->next != nullptr) { p->next->prior = s; }

    s->prior = p;
    p->next = s;

    return true;   
}

/**
 * @brief 删除节点 p 的后续节点
 * 
 * @param p 
 * @return true 
 * @return false 
 */
bool DeleteNextDNode(DLinkNode *p)
{
    if (p == nullptr) { return false; }
    DLinkNode *q = p->next;
    if (q == nullptr) { return false; }

    p.next = q->next;
    if(q->next != nullptr) {q->next->prior = p;}

    delete q;
    return true;
}

/**
 * @brief 清空销毁双链表 L
 * 
 * @param L 
 */
void DestroyList(DLinkList &L)
{
    while (L->next != nullptr) { DeleteNextDNode(L); }
    delete L;
    L = nullptr;
}

int main()
{
    DLinkNode* node1 = new DLinkNode;
    DLinkNode* node2 = new DLinkNode;
    DLinkNode* node3 = new DLinkNode;

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;

    InsertNextNode(node1, node2);
    InsertNextNode(node1, node3);

    cout << node1->next->data << " " << node1->next->next->data;
}
