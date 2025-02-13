#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *insertAtFront(Node *head, int value)
{
    Node *new_node = new Node(value);

    new_node->next = head;

    return new_node;
}

// node at a specific place
Node *insertAtPosition(Node *head, int value, int pos)
{
    Node *new_node = new Node(value);

    if (pos == 1)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp; ++i)
    {
        temp = temp->next;
    }

    if (temp)
    {
        cout << "Position out of bound" << endl;
        delete new_node;
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(10);
    head = insertAtFront(head, 24);
    head = insertAtPosition(head, 12, 3);

    printlist(head);

    return 0;
}
