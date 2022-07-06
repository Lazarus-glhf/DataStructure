#include <iostream>
using namespace std;

#define ElemType int

struct LNode
{
    ElemType data;
    LNode* next;
};

typedef LNode* LinkList;

bool InitializeNode(LNode*& node)
{
    node = new LNode;
    if (node == nullptr)
    {
        return false;
    }

    node->data = 0;
    node->next = nullptr;

    return true;
}

LinkList List_HeadInsert(LinkList& l)
{
    InitializeNode(l);
    ElemType x;

    cin >> x;
    if (x == 9999)
    {
        return l;
    }
    l->data = x;

    cin >> x;
    while(x != 9999)   
    {
        LNode* head = new LNode;
        head->next = l;
        head->data = x;
        l = head;

        cin >> x;
    }

    return l;   
}

LinkList List_EndInsert(LinkList& l)
{
    InitializeNode(l);
    ElemType data;
    LNode* node = l;

    cin >> data;
    if (data == 9999)   return l;
    l->data = data;

    cin >> data;
    while (data != 9999)
    {
        LNode* tailNode = new LNode;
        tailNode->data = data;
        tailNode->next = nullptr;

        node->next = tailNode;
        node = tailNode;

        cin >> data;
    }
    
    return l;
}

/**
 * @brief 指定节点尾插操作
 * 
 * @param l 
 * @param i 
 * @param data 
 * @return true 
 * @return false 
 */
bool ListInsert(LinkList& l, int i, ElemType data)
{
    if (i < 1) return false;

    if (i == 1)
    {
        LNode* s = new LNode;
        s->data = data;
        s->next = l;
        l = s;

        return true;
    }

    int j = 1;
    LNode* p = l->next;

    while(p != nullptr && j < i - 1)
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

/**
 * @brief 指定节点前插操作
 * 
 * @param node 
 * @param e 
 * @return true 
 * @return false 
 */
bool ListInsertPriorNode(LNode* node, ElemType e)
{
    if (node == nullptr) return false;

    LNode* s = new LNode;
    if (s == nullptr) return false;

    s->next = node->next;
    node->next = s;
    s->data = node->data;
    node->data = e;

    return true;
}

/**
 * @brief 
 * 
 * @param l 
 * @param location 
 * @return true 
 * @return false 
 */
bool ListDeleteNode(LinkList& l, int location)
{
    if (location < 1) return false;
    
    LNode* node = l;
    int j = 0;
    while (node != nullptr && j < location - 1)
    {
        node = node->next;
        j++;
    }

    if (node == nullptr && node->next == nullptr) return false;
    
    LNode *d = node->next;
    node->next = d->next;
    delete d;

    return true;
}

/**
 * @brief 按位查找
 * 
 * @param l 
 * @param location 
 * @param e 
 * @return LNode* 
 */
LNode* ListGetElem(LinkList& l, int location, ElemType& e)
{
    if (location < 1) return nullptr;

    LNode* node = l->next;
    int j = 0;
    while(node != nullptr && j < location - 1)
    {
        node = node->next;
        j++;
    }

    return node;
}

/**
 * @brief 按值查找
 * 
 * @param l 
 * @param e 
 * @return LNode* 
 */
LNode* LocateElem(LinkList& l, ElemType e)
{
    LNode* p = l->next;

    while (p != nullptr && p->data != e) p = p->next;

    return p;
}

/**
 * @brief 获取链表长度
 * 
 * @param l 
 * @return int 
 */
int ListLength(LinkList& l)
{
    int length = 0;
    LNode* node = l->next;
    while (node != nullptr)
    {
        node = node->next;
        length++;
    }

    return length;
}

int main()
{
    LinkList l;
    List_EndInsert(l);

    LNode* node = l;
    while(node != nullptr)
    {
        cout << node->data << '\n';
        node = node->next;
    }
}