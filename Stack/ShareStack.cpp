#include <iostream>
using namespace std;

#define Elemtype int
#define MaxSize 5

struct ShareStack
{
    Elemtype Stack[MaxSize];
    int top0;
    int top1;
};

void InitStack(ShareStack &S)
{
    S.top0 = -1;
    S.top1 = MaxSize;
}

bool Push0(ShareStack &S, Elemtype e)
{
    if (S.top0 == S.top1 - 1) { return false; }

    S.top0 += 1;
    S.Stack[S.top0] = e;
    // S.Stack[++S.top0] = e;

    return true;
}

bool Push1(ShareStack &S, Elemtype e)
{
    if (S.top0 == S.top1 - 1) { return false; }

    S.top1 -= 1;
    S.Stack[S.top1] = e;
    // S.Stack[--S.top1] = e;

    return true;
}

bool Pop0(ShareStack &S, Elemtype &e)
{
    if (S.top0 == -1) { return false; }

    e = S.Stack[S.top0];
    S.top0 -= 1;
    // e = S.Stack[S.top0--];

    return true;
}

bool Pop1(ShareStack &S, Elemtype &e)
{
    if (S.top1 == MaxSize) { return false; }

    e = S.Stack[S.top1];
    S.top1 += 1;
    // e = S.Stack[S.top0++];

    return true;
}

bool Empty(ShareStack &S)
{
    if (S.top0 == -1 && S.top1 == MaxSize) { return true; }

    return false;
}

// Test Function
void TestShareStack()
{
    ShareStack SS;
    InitStack(SS);

    Push0(SS, 1);
    Push0(SS, 2);
    Push0(SS, 3);
    Push1(SS, 5);
    Push1(SS, 6);

    if (!Push1(SS, 0)) { printf("check push1\n"); }
    if (!Push0(SS, 0)) { printf("check push0\n"); }
    
    int e;
    cout << "test pop0\n";
    while (Pop0(SS, e))
    {
        cout << e << "\n";
    }

    cout << "test pop1\n";
    while (Pop1(SS, e))
    {
        cout << e << "\n";
    }

}

int main()
{
    TestShareStack();

    return 0;
}
