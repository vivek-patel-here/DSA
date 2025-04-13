#include <iostream>
#include <vector>
using namespace std;

void heapify (vector<int> &arr,int n){
    int size=arr.size()-1;
    n = n<=size/2?n:size/2;
    int largest =n;
    int leftChild = 2*n;
    int rightChild =2*n+1;
    if(leftChild<arr.size() && arr[leftChild]>arr[largest]) largest =leftChild;
    if(rightChild<arr.size() && arr[rightChild]>arr[largest]) largest=rightChild;
    if(largest!=n){
        int temp  = arr[n];
        arr[n]=arr[largest];
        arr[largest]=temp;
        heapify(arr,largest);
    }
}

int main(){
    vector<int> arr ={-1,59,58,48,100,96};
    cout<<"Given Array : ";
    for(int el : arr){
        cout<<el<<" ";
    }cout<<endl;

    for(int i = (arr.size()-1)/2;i>0;i--) heapify(arr,i);
    cout<<"After Heapify  : ";
    for(int el : arr){
        cout<<el<<" ";
    }cout<<endl;

 }