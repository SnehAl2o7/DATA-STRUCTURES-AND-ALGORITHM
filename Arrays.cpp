#include<bits/stdc++.h>
#include<iterator>
using namespace std;
 
int main(){

    // initialising an array
    int array [5]; // 5 is the length of the array

    //assigning values ofarray
    array[0] = 1, array[2] = 3;

    // transversing an array
    for(int i = 0;i<5;i++){
        array[i] = i+1;
        cout<<array[i]<<endl;
    }

    //to access the length of array
    int length = sizeof(array)/sizeof(array[0]);
    cout<<length<<endl;

}

// Some basic questions 

