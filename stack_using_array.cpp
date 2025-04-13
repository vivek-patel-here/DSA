#include <iostream>
#include <vector>
using namespace std;
class stkImp
{
private:
    int top = -1;
    int size=10;
    int arr[10];

public:
    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "Overflow Error!"<<endl;
            return;
        }
        top++;
        arr[top] =x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "UnderFlow Error!"<<endl;;
            return -1;
        }
        top--;
        return arr[top + 1];
    }
    int getSize()
    {
        return top + 1;
    }
    int getTop()
    {
        if (top==-1) return -1;
        return arr[top];
    }
};

int main()
{
    stkImp stk;
    cout<<stk.getTop()<<endl;
    stk.pop();
    stk.push(100);
    cout<<stk.getSize()<<endl;
    cout<<stk.getTop()<<endl;
}