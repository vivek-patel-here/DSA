#include <iostream>
using namespace std;
#include <stack>

class stackQ {
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x){
        while(!s1.empty())
        {
            int data = s1.top();
            s2.push(data);
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            int data =s2.top();
            s1.push(data);
            s2.pop();
        }
    }

    int pop(){
        if(s1.empty()) return -1;
        int data = s1.top();
        s1.pop();
        return data;
    }
};