#include <bits/stdc++.h>
using namespace std;
#include <stack>

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

// DFS approach
//   LEFT - ROOT - RIGHT
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void rinorder(Node *root)
{
    if (root == NULL)
        return;

    // Creating an empty stack and push root
    stack<Node *> st;
    Node *curr = root;

    while (curr != NULL || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}
// ROOT - LEFT - RIGHT
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void rpreorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        cout << curr->data << " ";
        st.pop();
        if (curr->right)
        {
            st.push(curr->right);
        }
        if (curr->left)
        {
            st.push(curr->left);
        }
    }
}

// LEFT - ROOT - RIGHT
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void rpostorder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st1, st2;
    st1.push(root);
    Node *curr;

    while (!st1.empty())
    {
        curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }

    while (!st2.empty())
    {
        curr = st2.top();
        st2.pop();
        cout << curr->data << " ";
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
    root->right->right = new Node(7);

    cout << "Post order representation" << endl;
    postorder(root);
    cout << "\n Iterative Post order representation" << endl;
    rpostorder(root);

    cout << "\nPre order representation" << endl;
    preorder(root);

    cout << "\n Iterative Preorder representation " << endl;
    preorder(root);

    cout << "\n In order representation" << endl;
    inorder(root);

    cout << "\n Iterative Inorder representation : " << endl;
    rinorder(root);

    cout << "\nPre order representation" << endl;
    preorder(root);

    cout << "\n In order representation" << endl;
    inorder(root);
}