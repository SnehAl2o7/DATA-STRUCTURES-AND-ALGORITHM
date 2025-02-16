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

void printList(Node *n)
{
    Node *temp = n;
    while (temp->next != n)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << "->NULL" << endl;
}

void CircularLL(Node *head)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = head;
}

bool isCircular(Node *head)
{
    if (head == nullptr)
    {
        return false;
    }
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    CircularLL(head);
    printList(head);
    cout << isCircular(head) << endl;
}
