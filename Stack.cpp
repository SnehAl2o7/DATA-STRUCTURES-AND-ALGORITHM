#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top;
    vector<int> arr;

    Stack()
    {
        top = -1;
    }
};

bool isEmpty(Stack *&s)
{
    return s->top == -1;
}

void push(Stack *&s, int val)
{
    s->arr.push_back(val);
    s->top++;
}

void pop(Stack *&s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty" << endl;
        return;
    }

    int val = s->arr[s->top];
    s->top--;
    s->arr.pop_back();
}

int peek(Stack *&s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return s->arr[s->top];
}

int main()
{
    Stack *s = new Stack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    cout << peek(s) << endl; // prints 30
    pop(s);
    cout << peek(s) << endl;
    pop(s);
    cout << peek(s) << endl;
    pop(s);
    cout << peek(s) << endl;
    return 0;
}