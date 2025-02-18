#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int value;
    int priority;
} item;

item pr[100000];
int size = -1;

void enqueue(int value, int priority)
{
    size++;
    pr[size].value = value;
    pr[size].priority = priority;
}

int peek()
{
    int high = INT_MIN;
    int ind = -1;

    for (int i = 0; i <= size; i++)
    {
        if (high == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
        {
            high = pr[i].priority;
            ind = i;
        }
        else if (high < pr[i].priority)
        {
            high = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}

void dequeue()
{
    int ind = peek();
    for (int i = ind; i < size; i++)
    {
        pr[i] = pr[i + 1];
    }
    size--;
}

int main()
{
    /*
    THE PRIORITY QUEUE ARRANGE THE ELEMENTS ACCORDING TO THEIR PRIORITY VALUES
    IT IS USED IN ALGO OF TREES AND GRAPHS
    */
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 1);
    enqueue(40, 4);

    int ind = peek();
    cout << pr[ind].value << endl;

    dequeue();

    ind = peek();
    cout << pr[ind].value << endl;

    dequeue();

    ind = peek();
    cout << pr[ind].value << endl;

    return 0;
}