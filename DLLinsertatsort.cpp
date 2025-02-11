#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* prev, *next;
};

Node* sortedInsert(Node* &head, int x){
        Node* newNode = nullptr;
        newNode->data = x;
        Node* temp = head;
        if(temp->data > x){
            newNode->next = temp;
            temp->prev = newNode;
            head = temp;
            return head;
        }
        while(temp->next->data < x){
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        head = temp;
        return head;
}
int main(){
    int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    
}