#include <iostream>
#include <queue>
using namespace std;

class QStack{
    queue<int> MyQueue;
    int size;

    QStack(){
        size = 0;
    }
    public:
        void push(int x){
            if(size==0){
                MyQueue.push(x);
                size++;
                return;
            }
            MyQueue.push(x);
            for(int i=0;i<size;i++){
                int data =MyQueue.front();
                MyQueue.pop();
                MyQueue.push(data);
            }
        }
        void pop(){
            if(MyQueue.empty()) return ;
            MyQueue.pop();
            size--;
        }
};

