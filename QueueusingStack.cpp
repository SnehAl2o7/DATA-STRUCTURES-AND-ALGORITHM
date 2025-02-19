#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top;
    int n;
    vector<int> arr;

    Stack(int size)
    {
        top = -1;
        n = size;
        arr.resize(n);
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == n - 1;
    }

    void push(int data)
    {
        if (isFull())
        {
            return;
        }
        arr[++top] = data;
    }

    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        arr[top--] = 0;
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top];
    }
};

class Queue
{
public:
    Stack *s1;
    Stack *s2;
    int size;

    Queue(int n)
    {
        size = n;
        s1 = new Stack(n);
        s2 = new Stack(n);
    }

    bool isEmpty()
    {
        return s1->isEmpty();
    }

    bool isFull()
    {
        return s1->isFull();
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        while (!s1->isEmpty())
        {
            s2->push(s1->peek());
            s1->pop();
        }
        s1->push(data);

        while (!s2->isEmpty())
        {
            s1->push(s2->peek());
            s2->pop();
        }
    }

    void dequeue()
    {
        if (s1->isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        int x = s1->peek();
        cout << "Dequeued -> " << x << endl;
        s1->pop();
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return s1->peek();
    }
};

int main()
{
    Queue *q = new Queue(5);
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    cout << q->peek() << endl;
    q->dequeue();
    cout << q->peek() << endl;
    q->dequeue();
    cout << q->peek() << endl;
    q->dequeue();
    cout << q->peek() << endl;
    q->dequeue();
    cout << q->peek() << endl;
    q->dequeue();
}