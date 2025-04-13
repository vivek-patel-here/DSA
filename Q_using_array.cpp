#include <iostream>
#include <vector>
using namespace std;
class QImp
{
private:
    int head = 0;
    int tail = -1;
    int size=10;
    int arr[10];

public:
    void push(int x)
    {
        if (head == size )
        {
            cout << "Overflow Error!"<<endl;
            return;
        }
        if(tail==-1){
            arr[0] =x;
            head++;
            tail++;
            return;
        }
        arr[head] =x;
        head=(head+1)%size;
    }

    int pop()
    {
        if (tail == -1)
        {
            cout << "UnderFlow Error!"<<endl;;
            return -1;
        }
        tail=(tail+1)%size;
        return arr[tail - 1];
    }
    int getSize()
    {   
        if(tail==-1) return 0;
        return head-tail;
    }
    int getTop()
    {
        if (tail==-1) return -1;
        return arr[tail];
    }
};

int main()
{
    QImp Q;
    cout<<Q.getTop()<<endl;
    Q.pop();
    Q.push(100);
    cout<<Q.getSize()<<endl;
    cout<<Q.getTop()<<endl;
}