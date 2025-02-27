#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    stack<pair<int, int>> s;

public:
    Solution()
    {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        int newMin = s.empty() ? x : min(x, s.top().second);

        // we push the pair of given element and newMin into stack
        s.push({x, newMin});
    }

    // Remove the top element from the Stack
    void pop()
    {
        if (!s.empty())
        {
            s.pop();
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        if (s.empty())
        {
            return -1;
        }

        int top = s.top().first;
        return top;
    }

    // Finds minimum element of Stack
    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }

        int mn = s.top().second;
        return mn;
    }
};

class Solution
{
private:
    stack<pair<int, int>> s;

public:
    Solution()
    {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        int newMin = s.empty() ? x : min(x, s.top().second);

        // we push the pair of given element and newMin into stack
        s.push({x, newMin});
    }

    // Remove the top element from the Stack
    void pop()
    {
        if (!s.empty())
        {
            s.pop();
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        if (s.empty())
        {
            return -1;
        }

        int top = s.top().first;
        return top;
    }

    // Finds minimum element of Stack
    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }

        int mn = s.top().second;
        return mn;
    }
};