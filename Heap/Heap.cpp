#include <iostream>

template <typename T>
class MaxHeap
{
private:
    T* data;
    int count;

public:
    MaxHeap(int capacity)
    {
        data = new T[capacity + 1];
        count = 0;
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0;
    }
};

int main()
{
    MaxHeap<int>* maxHeap = new MaxHeap<int>(100);
    printf("%d\n", maxHeap->size());
    printf("%d", maxHeap->isEmpty());
}