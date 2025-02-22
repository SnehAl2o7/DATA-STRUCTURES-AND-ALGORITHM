#include <bits/stdc++.h>
using namespace std;

// BINARY TREE CLASS REPRESENTATION.
class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

    Tree(int d)
    {
        data = d;
        left = right = NULL;
    }
};

int main()
{
    // Initilize and allocate memory for tree nodes
    Tree *first = new Tree(1);
    Tree *second = new Tree(2);
    Tree *third = new Tree(3);
    Tree *fourth = new Tree(4);

    // Connect binary tree nodes
    first->left = second;
    first->right = third;
    second->left = fourth;
    return 0;
}
