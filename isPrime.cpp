#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num) {
    bool result= true;
    int sqroot = sqrt(num);
    for(int i=2;i<=sqroot;i++){
        if(num%i==0){
            result=false;
        }
    }
    return result;
}

int main(){
    int num = 53;
    cout<<isPrime(num);
    cout<<"vivek";
}