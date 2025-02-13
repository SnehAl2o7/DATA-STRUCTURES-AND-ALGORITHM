#include <bits/stdc++.h>
using namespace std;

int main()
{
    // DECLARING AN ARRAY
    int arr[10] = {0}; // size
    // make all value default to 0
    // accessing the variables of the array
    arr[0] = 10;
    arr[1] = 20;

    // SIZE OF ARRAY
    cout << sizeof(arr) / sizeof(arr[0]) << endl;

    // Iterating over the array
    for (int i : arr)
    {
        cout << i << endl; // if value was not given
    }

    // DYNAMIC ARRAY
    int *a = new int[10]; // 10 can be replace with a variable
    a[0] = 10;
    a[1] = 20;
    cout << sizeof(*a) << endl;
    // rest of the operation are same as of array
    // deleting the array
    delete[] a;
    return 0;
}