/**
 * @file StaticLinearList.cpp
 * @author Lazarus 
 * @brief 静态分配内存的顺序表
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
using namespace std;

#define MAX_SIZE 20

struct LinearList
{
    int list[MAX_SIZE];
    int length;
};

/**
 * @brief 初始化线性表
 * 
 * @param list 
 */
void initializeList(LinearList& list)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list.list[i] = 0;
    }
    list.length = 0;
}

/**
 * @brief 插入
 * @param list 传入的列表
 * @param elem 要插入的元素
 * @param location 插入的位置
 * @return 是否成功插入
 */
bool insert(LinearList& list, int elem, int location)
{
    if (location > list.length + 1 || location < 1 || list.length + 1 > MAX_SIZE)
    {
        return false;
    }

    for (int i = list.length + 1; i >= location; i--)
    {
        list.list[i] = list.list[i - 1];
    }

    list.list[location - 1] = elem;
    list.length++;

    return true;
}

/**
 * @brief 删除
 * 
 * @param list 
 * @param location 
 * @return true 
 * @return false 
 */
bool deleteElement(LinearList& list, int location)
{
    if (list.length == 0 || location < 1 || location > list.length)
    {
        return false;
    }

    for (int i = location - 1; i < list.length; i++)
    {
        list.list[i] = list.list[i + 1];
    }

    return true;
}

/**
 * @brief Get the Elem object
 * 
 * @param l 传入的线性表
 * @param location 查询的位置
 * @param elem 返回数据的容器
 * @return true 
 * @return false 
 */
bool getElem(LinearList& l, int location, int elem)
{
    if (l.length == 0 || l.length < location || location < 1)
    {
        return false;
    }

    elem = l.list[location];
    return true;
}
/**
 * @brief 按值查找
 * 
 * @param l 传入的线性表
 * @param elem 值
 * @return int 地址，未找到则为 0
 */
int locateElem(LinearList& l, int elem)
{
    for (int i = 0; i < l.length; i++)
    {
        if (l.list[i] == elem)
        return i + 1;
    }
    return -1;
}

int main()
{
    LinearList l;
    initializeList(l);
    insert(l, 5, 1);
    printf("%d\n", l.list[0]);
    deleteElement(l, 1);
    printf("%d", l.list[0]);

}i