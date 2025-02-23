#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void heapify(vector<int> &arr, int n, int i)
{
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[large])
    {
        large = l;
    }
    if (r < n && arr[r] > arr[large])
    {
        large = r;
    }

    if (large != i)
    {
        swap(arr[i], arr[large]);
        heapify(arr, n, large);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver's code
int main()
{
    vector<int> arr = {9, 4, 3, 8, 10, 2, 5};

    // Function call
    heapSort(arr);

    cout << "Sorted array is \n";
    printArray(arr);
}