#include <iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    public:
    ListNode(int val1){
        val=val1;
        next=nullptr;
    }

    public:
    ListNode(){
        val=0;
        next=nullptr;
    }
};

int getNumber(ListNode* LL){
    long long num=0;
    ListNode* mover=LL;
    long long pow = 1;
    while(mover){
        num+=(long long)(mover->val)*pow;
        pow*=10;
        mover=mover->next;
    }
    return num;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int num1=getNumber(l1);
    int num2=getNumber(l2);
    int sum = num1+num2;
    ListNode*head=new ListNode();
    ListNode*temp1=head;
    bool flag =true;
    while(sum){
        int val= sum%10;
        ListNode* temp2 =new ListNode(val);
        if(flag){
            temp1->val=val;
            flag=false;
        }else{
            temp1->next=temp2;
            temp1=temp1->next;
        }
        sum=sum-val;
        sum=sum/10;
    }
    return head;
}

int main(){
    
}