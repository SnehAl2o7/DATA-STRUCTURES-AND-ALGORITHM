#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* insertion(Node* &head,int data,int pos){
    if(head == nullptr){
        if(pos != 1){
            cout<<"Invalid position"<<endl;
            return head;
        }
        Node* newNode = new Node(data);
        head = newNode;
        head->next = head;
        return head;
    }

    Node* newNode = new Node(data);
    Node* curr = head->next;

    if(pos == 1){
        newNode->next = curr;
        head->next = newNode;
        return head;
    }

    for(int i = 1;i<pos-1;i++){
        curr = curr->next;
        if(curr == head->next){
            cout<<"Invalid  position"<<endl;
            return head;
        }
    }

    newNode->next =  curr->next;
    curr->next = newNode;

    if(curr == head)head = newNode;
    return head;
}

void printList(Node *last){
    if(last == NULL) return;

    Node *head = last->next;
    while(true){
        cout<<head->data<<" ";
        head = head->next;
        if(head == last->next) break;
    }
    cout<<endl;
}

int main (){

    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);

    Node *last = head->next->next;
    head->next = last;

    cout<< "Original list : ";
    printList(last);

    int data = 5 , pos = 2;
    last = insertion(last, data , pos);
    cout<< "List after insertion: ";
    printList(last);

    return 0;
}