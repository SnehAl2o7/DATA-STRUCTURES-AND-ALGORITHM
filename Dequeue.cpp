#include <bits/stdc++.h>
using namespace std;

void printdq(deque<int> dq)
{
    deque<int>::iterator it;
    for (it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    /*
    LEARNING USING DEQUEUE AND IT'S IMPLEMENTATION
    DEQUEUE IS A DOUBLE ENDED QUEUE
    IT IS OF TWO TYPES
    DEQUEUE WITH 2 FRONT AND ONE END
    OR DEQUEUE WITH 2 END AND ONE FRONT
    */

    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    cout << "The deque dq is : ";
    printdq(dq);

    cout << "Size -> " << dq.size() << endl;
    cout << "Max size -> " << dq.max_size() << endl;

    cout << "Front element -> " << dq.front() << endl;
    cout << "Back element -> " << dq.back() << endl;
    cout << "At index -> " << dq.at(2) << endl;

    cout << "Popping an element " << endl;
    dq.pop_front();
    printdq(dq);
    dq.pop_back();
    printdq(dq);

    return 0;
}
