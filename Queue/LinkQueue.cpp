#include <iostream>
using namespace std;

#define ElemType int

struct LinkNode
{
    ElemType data;
    LinkNode* next;
};

struct LinkQueue
{
    LinkNode* front;
    LinkNode* rear;
};

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new LinkNode;
    Q.front->next = nullptr;
}

bool Empty(LinkQueue Q)
{
    if (Q.rear == Q.front) { return true; }
    // if (Q.front == nullptr) { return true; }
    return false;
}

void EnQueue(LinkQueue &Q, ElemType e)
{
    LinkNode* node = new LinkNode;
    node->data = e;
    Q.rear->next = node;
    Q.rear = node;
}

bool DeQueue(LinkQueue &Q, ElemType &e)
{
    if (Empty(Q)) { return false; }

    LinkNode* node = Q.front->next;
    e = node->data;

    Q.front->next = Q.front->next->next;
    delete node;

    return true;
}

void test()
{
    LinkQueue Q;
    InitQueue(Q);

    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);

    ElemType e;
    while(DeQueue(Q, e))
    {
        cout << e << "\n";
    }
}

int main()
{
    test();
    
    return 0;
}
