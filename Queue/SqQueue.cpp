#include <iostream>
using namespace std;

#define ElemType int
#define MaxSize 10

// 环形队列
struct SqQueue
{
    ElemType Data[MaxSize];
    int front;
    int rear;
};

void InitSqQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q)
{
    if (Q.rear == Q.front) { return true; }
    return false;
}

bool QueueFull(SqQueue Q)
{
    if ((Q.rear + 1) % MaxSize == Q.front) { return true; }
    return false;
}

// 入队
bool EnQueue(SqQueue &Q, ElemType e)
{
    if (QueueFull(Q)) { return false; }
    
    Q.Data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;

    return true;
}

// 出队
bool DeQueue(SqQueue &Q, ElemType &e)
{
    if (QueueEmpty(Q)) { return false; }
    
    e = Q.Data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;

    return true;
}

bool GetElem(SqQueue &Q, ElemType &e)
{
    if (QueueEmpty(Q)) { return false; }

    e = Q.Data[Q.front];

    return true;
}

void test()
{
    SqQueue Queue;
    InitSqQueue(Queue);

    EnQueue(Queue, 1);
    EnQueue(Queue, 2);
    EnQueue(Queue, 3);

    ElemType e;
    while(DeQueue(Queue, e))
    {
        cout << e << "\n";
    }
}

int main()
{
    test();

    return 0;
}