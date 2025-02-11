#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    public:
        ListNode(int val) {
            this->data = val;
            this->next = nullptr;
        } 
};
    //Insertion at the end
void insertAtTail(ListNode* &head,int val){
    ListNode* newnode = new ListNode(val);

    if(head == nullptr){
        head = newnode;
        return ;
    }
    ListNode* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newnode;
    
}

    // insertion at the  beginning

void insertAtHead(ListNode* &head, int val){
    ListNode* newnode = new ListNode(val);
    newnode->next = head;
    head = newnode;
}

// insertion at the given index
void insertion(ListNode* &head,int position, int data){
    ListNode* newnode = new ListNode(data);
    if(position == 1){
        newnode->next = head;
        head = newnode;
        return;
    }

    ListNode* curr = head;
    for(int i = 1;i<position-1 && curr != nullptr;++i){
        curr = curr->next;
    }

    if(curr == nullptr){
        cout<<"Position is out of bound"<<endl;
        delete newnode;
        
    }
    newnode->next = curr->next;
    curr->next = newnode;
}

// searching in the link list
// using iteration
bool searching(ListNode* &head,int val){
    ListNode* temp = head;
    while(temp != nullptr){
        if(temp->data == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//using recursion
bool researching(ListNode* &head,int val){

    if(head == NULL){
        return  false;
    }
    if(head->data == val){
        return true;
    }

    return researching(head->next,val);
}

//deletion of link list
void deletion(ListNode* &head,int pos){
    
    ListNode* prev;
    ListNode* temp = head;
    
    if(temp == NULL){
        return;
    }
    if(pos == 1){
        head = temp->next;
        free(temp);
        return;
    }

    for(int i = 1;i != pos;i++){
        prev = temp;
        temp = temp->next;
    }

    if(temp != NULL){
        prev->next = temp->next;
        free(temp);
    }
    else {
        cout<<"Data not found"<<endl;   
    }
}

// reversing a link list

void reverse(ListNode* &head){
    ListNode*  prev = NULL;
    ListNode*  curr = head;
    ListNode* next = NULL;

    while(curr != NULL){
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head = prev;
}

// printing link list
void printList(ListNode* head){
    ListNode*temp = head;
    while(temp != nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    ListNode* head = nullptr;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    printList(head);
    insertion(head,5,8);
    printList(head);

    cout<<searching(head,3)<<endl;
    cout<<researching(head,8)<<endl;
    cout<<searching(head,9)<<endl;
    cout<<researching(head,13)<<endl;

    printList(head);
    reverse(head);


    printList(head);       
    deletion(head,1);
    printList(head);
    deletion(head,5);
    printList(head);
    deletion(head,3);
    printList(head);
    
}




