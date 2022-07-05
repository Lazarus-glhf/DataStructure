#include <iostream>
using namespace std;

#define ElemType string

struct BSTNode
{
    ElemType data;
    BSTNode *lChild = nullptr;
    BSTNode *rChild = nullptr;
};

void CreateBSTree(BSTNode *&node)
{
    ElemType ch;
    cin >> ch;
    if (ch == "#")
        node = nullptr;
    else
    {
        node = new BSTNode;
        node->data = ch;
        CreateBSTree(node->lChild);
        CreateBSTree(node->rChild);
    }
}

// �������
void PreOrderTraverse(const BSTNode *node, int level)
{
    if (!node)
    {
        return;
    }
    else
    {
        cout << "val is : "
             << node->data
             << "\t"
             << "Level is : " << level << endl;
        PreOrderTraverse(node->lChild, level + 1);
        PreOrderTraverse(node->rChild, level + 1);
    }
}

// �������
void InOrderTraverse(const BSTNode *node, int level)
{
    if (!node)
    {
        return;
    }
    else
    {
        InOrderTraverse(node->lChild, level + 1);
        cout << "val is : "
             << node->data
             << "\t"
             << "Level is : " << level << endl;
        InOrderTraverse(node->rChild, level + 1);
    }
}

// �������
void PostOrderTraverse(const BSTNode *node, int level)
{
    if (!node)
    {
        return;
    }
    else
    {
        PostOrderTraverse(node->lChild, level + 1);
        PostOrderTraverse(node->rChild, level + 1);
        cout << "val is : "
             << node->data
             << "\t"
             << "Level is : " << level << endl;
    }
}

int main()
{
    BSTNode *bst;
    CreateBSTree(bst);

    cout << "���������" << endl;
    PreOrderTraverse(bst, 0);

    cout << "���������" << endl;
    InOrderTraverse(bst, 0);

    cout << "���������" << endl;
    PostOrderTraverse(bst, 0);

    return 0;
}
