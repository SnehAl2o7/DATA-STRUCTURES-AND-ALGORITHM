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

    if (temp == NULL)
    {
        cout << "Position out of bound" << endl;
        delete new_node;
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

Node *insertAtEnd(Node *head, int value)
{
    Node *new_node = new Node(value);
    if (head)
    {
        return new_node;
    }

    Node *last = head;
    while (last->next)
    {
        last = last->next;
    }

    last->next = new_node;
    return head;
}

Node *deleteNode(Node *head)
{
    if (head)
    {
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteNode(Node *head, int pos)
{
    Node *temp = head;
    Node *todelete;

    if (temp == nullptr)
    {
        return nullptr;
    }
    if (pos == 1)
    {
        todelete = head;
        head = head->next;
        delete todelete;
        return head;
    }

    for (int i = 1; i != pos; i++)
    {
        todelete = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        todelete->next = temp->next;
        delete temp;
    }

    else
    {
        cout << "Data not present.";
    }
    return head;
}

Node *deltelastNode(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }

    delete (temp->next);
    temp->next = nullptr;
    return head;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(10);
    head = insertAtFront(head, 24);
    head = insertAtPosition(head, 93, 3);
    printlist(head);
    head = deltelastNode(head);
    printlist(head);
    head = insertAtPosition(head, 34, 4);
    printlist(head);
    head = deleteNode(head, 34);
    printlist(head);
    return 0;
}
