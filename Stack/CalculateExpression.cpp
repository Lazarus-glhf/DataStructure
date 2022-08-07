#include <iostream>
#include "SqStack.cpp"

bool CalculateExpression(SqStack &stack, string str, Elemtype &ans)
{
    for (const auto i : str)
    {
        Elemtype a = 0;
        Elemtype b = 0;
        if (i == '+')
        {
            Pop(stack, a);
            Pop(stack, b);
            Push(stack, a + b);
            continue;
        }
        else if (i == '-')
        {
            Pop(stack, a);
            Pop(stack, b);
            Push(stack, a - b);
            continue;
        }
        else if (i == '*')
        {
            Pop(stack, a);
            Pop(stack, b);
            Push(stack, a * b);
            continue;
        }
        else if (i == '/')
        {
            Pop(stack, a);
            Pop(stack, b);
            Push(stack, a / b);
            continue;
        }
        else 
        {
            cout << i << endl;
            Push(stack, i - 48);
        }
    }
    Elemtype e;
    Pop(stack, e);
    if (Empty(stack))
    {
        ans = e;
        return true;
    }
    else
    {
        return false;
    }
}

// void test()
// {
//     // 1 + 2 + 3 + 4 + 5 * 6;
//     // 56*12++34++
//     string test = "56*12++34++";
//     Elemtype ans = 0;
//     SqStack s;
//     InitStack(s);
//     CalculateExpression(s, test, ans);
//     cout << ans;
// }