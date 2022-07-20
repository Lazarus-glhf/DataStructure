#include <iostream>
using namespace std;
#define ElemType int

struct DNode
{
    ElemType data;
    DNode* prior, *next;
};
typedef DNode* DLinkList;

bool InitDLinkList(DLinkList &L)
{
    L = new DNode;
    if (L == nullptr) { return false; }

    L->prior = L;
    L->next = L;

    return true;
}

bool Empty(DLinkList L)
{
    if (L->next == L) { return true; }
    else { return false; }
}

bool isTail(DLinkList L, DNode *p)
{
    if (p->next == L) { return true; }
    else { return false; }
}

void InsertNextNode(DNode* p, DNode* s)
{
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

void DeleteNextDNode(DNode* p, DNode* s)
{
    p->next = s->next;
    s->next->prior = p;

    delete s;
}

