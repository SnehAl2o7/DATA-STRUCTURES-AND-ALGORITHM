#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

//  BFS APPROACH TO REPRESENT A TREE
//  USING STACK AND RECURSION APPROACH
void BFSrec(Node *root, int level, vector<vector<int>> &res)
{

    if (root == NULL)
        return;

    if (res.size() <= level)
    {
        res.push_back({});
    }

    res[level].push_back(root->data);
    BFSrec(root->left, level + 1, res);
    BFSrec(root->right, level + 1, res);
}

vector<vector<int>> BFS(Node *root)
{
    vector<vector<int>> res;

    BFSrec(root, 0, res);
    return res;
}

// BFS APPROACH TO REPRESENT A TREE
// USING QUEUE APPROACH ITERATIVE
vector<vector<int>> IterativeBFS(Node *root)
{
    if (root == NULL)
        return {};

    queue<Node *> q;
    vector<vector<int>> res;

    q.push(root);
    int curr = 0;

    while (!q.empty())
    {
        int len = q.size();
        res.push_back({});
        for (int i = 0; i < len; i++)
        {
            Node *temp = q.front();
            q.pop();

            res[curr].push_back(root->data);

            if (root->left != nullptr)
            {
                q.push(root->left);
            }
            if (root->right != nullptr)
            {
                q.push(root->right);
            }
            curr++;
        }
        return res;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    vector<vector<int>> res = BFS(root);
    cout << "Recursive BFS Traversal of the tree is: \n";

    for (vector<int> level : res)
    {
        for (int node : level)
        {
            cout << node << " ";
        }
    }

    vector<vector<int>> ans = IterativeBFS(root);
    cout << "Iterative BFS Traversal of the tree is: \n";
    for (vector<int> level : res)
    {
        for (int node : level)
        {
            cout << node << " ";
        }
    }
}