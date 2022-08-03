#include <iostream>
using namespace std;

#define ElemType int

// LinkStack without head node
struct LinkNode
{
    ElemType data;
    LinkNode* next;
};
typedef LinkNode* LinkStack;

bool InitLStack(LinkStack &S, ElemType e)
{
    if (S != nullptr) { return false; }

    S = new LinkNode;
    S->data = e;
    S->next = nullptr;

    return true;
}

bool Push(LinkStack &S, ElemType e)
{
    if (S == nullptr) { return false; }
    
    LinkNode* node = new LinkNode;

    node->data = e;
    node->next = S;
    S = node;

    return true;
}

bool Pop(LinkStack &S, ElemType &e)
{
    if (S == nullptr) { return false; }

    LinkNode* node = S;
    S = S->next;

    e = node->data;
    delete node;

    return true;
}

bool GetTop(LinkStack S, ElemType &e)
{
    if (S == nullptr) { return false; }

    e = S->data;

    return true;
}

bool Empty(LinkStack S)
{
    if (S == nullptr ) return true;

    return false;
}

void Print(LinkStack S)
{
    LinkNode* node = S;
    while (node != nullptr)
    {
        cout << node->data << "\n";
        node = node->next;
    }
}

// Test Function
void Test()
{
    LinkStack S;
    InitLStack(S, 1);
    Push(S, 2);
    Push(S, 3);

    cout << "Printing\n";
    Print(S);

    cout << "Poping\n";
    ElemType e;
    while(Pop(S, e))
    {
        cout << e << "\n";
    }
}

int main()
{
    Test();

    return 0;
}