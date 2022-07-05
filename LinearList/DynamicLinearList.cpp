/**
 * @file DynamicLinearList.cpp
 * @author Lazarus
 * @brief 动态分配内存的顺序表
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

struct DynamicLinearList
{
    int* list;
    int length;
    int capacity;
};

/**
 * @brief 初始化线性表
 * 
 * @param l 传入的线性表
 * @param size 创建的大小
 * @return true 
 * @return false 若线性表不为空则拒绝创建
 */
bool initializeList(DynamicLinearList& l, int size)
{
    // if (l.list != nullptr)
    // {
    //     return false;
    // }

    l.list = new int[size];
    l.length = 0;
    l.capacity = size;

    return true;
}

/**
 * @brief 插入
 * 
 * @param l 传入的线性表
 * @param elem 
 * @param location 
 * @return true 
 * @return false 
 */
bool insert(DynamicLinearList& l, int elem, int location)
{
    if (l.length + 1 < location || location < 1 || l.length == l.capacity)
    {
        return false;
    }

    for (int i = l.length + 1; i >= location; i--)
    {
        l.list[i] = l.list[i - 1];
    }

    l.list[location - 1] = elem;
    l.length++;

    return true;
}

bool deleteElem(DynamicLinearList& l, int location)
{
    if (location > l.length + 1 || location < 1)
    {
        return false;
    }

    for (int i = location - 1; i < l.length; i++)
    {
        cout << "trying deleting\n";
        l.list[i] = l.list[i + 1];
    }

    l.length--;

    return true;
}
int main()
{
    DynamicLinearList l;
    initializeList(l, 10);
    cout << l.length << '\n';
    insert(l, 5, 1);
    cout << l.list[0] << '\n';
    deleteElem(l, 1);
    cout << l.list[0];

    return 0;
}