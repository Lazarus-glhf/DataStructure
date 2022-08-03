#include <iostream>
using namespace std;

#define Elemtype int
#define MaxSize 10

struct SqStack
{
    Elemtype Stack[MaxSize];
    int top;
};

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool Push(SqStack &S, Elemtype e)
{
    if (S.top == MaxSize - 1) { return false; }

    S.top += 1;
    S.Stack[S.top] = e;
    // S.Stack[++S.top] = e;

    return true;
}

bool Pop(SqStack &S, Elemtype &e)
{
    if (S.top == -1) { return false; }

    e = S.Stack[S.top];
    S.top -= 1;
    // e = S.Stack[S.top--];

    return true;
}

bool Empty(SqStack &S)
{
    if (S.top == -1) { return true; }

    return false;
}

void TestStack()
{
    int i = 0;
    int m = 0;
    SqStack S;
    InitStack(S);

    while (Push(S, ++i))
    {
        printf("pushing\n");
    }

    while (Pop(S, m))
    {
        printf("%d\n", m);
    }
}