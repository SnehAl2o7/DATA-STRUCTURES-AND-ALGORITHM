#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int l,int m,int r){
    int n1 = m-l+1;
    int  n2 = r-m;

    int a[n1], b[n2];

    for(int i = 0;i<n1;i++){
        a[i] = arr[l+i];
    }

    for(int i = 0;i<n2;i++){
        b[i] = arr[m+1+i];
    }

    int i = 0, j= 0, k = l;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            k++; i++;
        }
        else {
            arr[k] = b[j];
            k++; j++;
        }
    }

    while(i < n1){
        arr[k] = a[i];
        k++; i++;
    }

    while(j < n2){
        arr[k] = b[j];
        k++; j++;
    }
}


void MergeSort(int arr[],int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,h);
        Merge(arr,l,mid,h);
    }
}

int main(){
     int arr [] = {5,1,4,8,2,7,3,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting :"<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    MergeSort(arr,0,n-1);

    cout<<"After sorting :"<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}