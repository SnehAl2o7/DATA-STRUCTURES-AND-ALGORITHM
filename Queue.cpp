#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int front, rear;
    vector<int> arr;

    Queue()
    {
        front = rear = -1;
    }
    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int val)
    {
        if (rear == -1)
        {
            front = rear = 0;
        }
        arr.push_back(val);
        rear++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued " << arr[front] << endl;
        front++;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue *q = new Queue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    cout << q->peek() << endl;
    q->dequeue();
    cout << q->peek() << endl;
    q->dequeue();
    cout << q->peek() << endl;
    q->dequeue();
    cout << q->peek() << endl;
    q->dequeue();
}