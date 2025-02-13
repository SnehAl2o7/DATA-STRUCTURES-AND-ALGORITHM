#include <bits/stdc++.h>
using namespace std;

int main()
{
    // initializing vector and declaring it
    vector<int> v = {1, 2, 3, 4, 5};
    // Traversing a vector
    //  for (int i : v){
    //      cout << i << " ";
    //  }

    vector<int> vec(5, 20); // initializing vector with 5 elements and all elements are 0

    // Basic vector operations
    // Accessing
    cout << v[0] << endl;
    cout << vec.at(0);

    // Updating
    v[0] = 10;
    vec[4] = 90;

    // inseting an element
    //  at end
    v.push_back(10);
    vec.push_back(10);
    // inserting at a index
    v.insert(v.begin() + 2, 10);
    vec.insert(vec.begin() + 2, 10);
    // deleting an element
    v.pop_back();         // deletes the last element
    vec.erase(v.begin()); // removing at index

    // sorting a vector
    sort(v.begin(), v.end());
    *v.begin(); // begin of vecotr return as pointer
    *v.end();   // end of vector return as pointer
    return 0;
}