#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void insertion(Node* &head,int val,int pos){
    Node* newNode = new Node(val);

    if(pos == 1){
        newNode->next = head;
        if(head != nullptr){
            head->prev = newNode;
        }
        head = newNode; 
        return;
    }

    Node*  curr = head;

    for(int i = 1;i<pos-1 && curr!=nullptr;i++){
        curr = curr->next;
    }

    if(curr == nullptr){
        cout<<"Position is out of bound"<<endl;
        free(newNode);
        return ;
    }

    newNode->prev = curr;
    newNode->next = curr->next;
    curr->next = newNode;

    if(newNode->next != nullptr){
        newNode->next->prev = newNode;
    }
}

void InsertAtEnd(Node* &head,int newnode){
    Node* newNode = new Node(newnode);

    if(head == nullptr){
        head = newNode;
    }
    else {
        Node* last = head;
        while(last->next != nullptr){
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
}

void deletion(Node* &head,int pos){
    if(!head){
        cout<<"List is empty"<<endl;
        return ;
    }

    Node* curr = head;
    for(int i = 1;i<pos && curr;i++){
        curr = curr->next;
    }

    if(!curr){
        return;
    }

    if(curr->prev){
        curr->prev->next = curr->next;
    }
    if(curr->next){
        curr->next->prev = curr->prev;
    }

    if(head == curr){
        head = curr->next;
    }

    free(curr);
}

void printdoublyll(Node* head){
    Node* curr = head;
    while(curr !=  nullptr){
        cout<<curr->data<<"<=>";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = nullptr;
    InsertAtEnd(head,1);
    InsertAtEnd(head,2);
    InsertAtEnd(head,3);
    InsertAtEnd(head,4);
    InsertAtEnd(head,5);
    insertion(head,7,2);
    printdoublyll(head);
    deletion(head,3);
    printdoublyll(head);
    deletion(head,1);
    printdoublyll(head);    
    deletion(head,4);
    printdoublyll(head); 
}