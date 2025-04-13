#include <iostream>
using namespace std;

class LL{
    public:
    int val ;
    LL* Next;
    LL(int data){
        val=data;
        Next=nullptr;
    }
};

//**************stack using LL */
class LLStack{
    int size;
    LL* top;

    public:
    LLStack(){
        top=nullptr;
        size=0;
    }
    void push(int data){
        LL* newNode = new LL(data);
        newNode->Next =top;
        top = newNode;
        size++;
    }

    int pop(){
        if(size==0) return -1;
        LL* temp =top;
        top=top->Next;
        int val = temp->val;
        delete temp;
        size--;
        return val;
    }
};

// ****************Queue using LL****************************

class LLQ{
    int size;
    LL* front;
    LL* rear;

    LLQ(){
        size =0;
        front=nullptr;
        rear=nullptr;
    }

    public:
    void push(int data){
        LL* newNode =new LL(data);
        if(rear==nullptr or front==nullptr){
            front=newNode;
            rear=newNode;
            size++;
            return;
        }
        rear->Next=newNode;
        rear= rear->Next;
        size++;
    }

    int pop(){
        if(front==nullptr){
            return -1;
        }
        LL* temp =front ;
        front = front->Next;
        int val = temp->val;
        delete temp;
        size--;
        return val;
    }
};