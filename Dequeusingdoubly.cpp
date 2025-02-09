#include<bits/stdc++.h>
using namespace std;

class Dnode {
    public:
        int data;
        Dnode* next;
        Dnode* prev;

        Dnode(int x){
            data = x;
            next = prev = nullptr;
        }
};

class Deque {
    Dnode* front, *rear;
    int size;

    public :
        Deque(){
            size = 0;
            front = rear = nullptr;
        }
        void insertFront(int data);
        void insertRear(int data);
        void deleteFront();
        void deleteRear();
        int getFront();
        int getRear();
        int Size();
        void display();
        bool isEmpty();
        //void erase();
};

bool Deque :: isEmpty(){
    return (front == nullptr);
}

int Deque :: Size(){ return size;}

void Deque :: insertFront(int data){
    Dnode * new_node = new Dnode(data);
    if(isEmpty()){
        front = rear = new_node;
    }
    else{
        new_node->next = front;
        front->prev = new_node;
        front = new_node;
    }
    size++;
    cout<<data<<" inserted at the front.\n";
}

void Deque :: insertRear(int data){
    Dnode * new_node = new Dnode (data);

    if(isEmpty()){
        
    front = rear = new_node;
    }
    else {
        new_node->prev = rear;
        rear->next = new_node;
        rear = new_node;

    }
    size++;
    cout<<"value "<<"insert at the end";
}

void Deque :: deleteFront(){
    if(isEmpty()){
        cout<<"Deque is empty.\n";
        return ;
    }
    size--;
    Dnode*temp = front;
    front = front->next;

    if(front != nullptr){
        front->prev = nullptr;
    }else {
        rear = nullptr;
    }

    cout<<temp->data << "  deleted from the front.\n";
    delete temp;
}

void  Deque :: deleteRear(){
    if(isEmpty()){
        cout<<"Deque is empty.\n";
        return;
    }

    size--;
    Dnode* temp = rear;
    rear = rear->prev;
    if(rear != nullptr){
        rear->next = nullptr;
    }else {
        front =  nullptr;
    }

    cout<<temp->data << " deleted from the rear. \n";
    delete  temp;
}

int Deque :: getFront(){
    if(isEmpty()){
        cout<<"Deque is empty.\n";
        return -1;
    }
    return front->data ;
}

int  Deque :: getRear(){
    if(isEmpty()){
        cout<<"Deque is empty.\n";
        return -1;
    }

    return rear ->data;
}

void Deque :: display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        Dnode* temp = front;
        cout << "Deque elements: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
int main(){
Deque dq;

    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.insertRear(40);

    dq.display();

    std::cout << "Front element: " << dq.getFront() << "\n";
    std::cout << "Rear element: " << dq.getRear() << "\n";

    dq.deleteFront();
    dq.display();

    dq.deleteRear();
    dq.display();

    return 0;
}