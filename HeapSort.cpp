#include <iostream>
#include <vector>
using namespace std;
void print_heap(vector<int>& heap)
{
    for (int i = 1; i < heap.size(); i++) cout << heap[i] << " ";
    cout << endl;
}

void heapSort(vector<int> &heap,int size){
    if(size<=0) return;
    //Swaping first and last element
    int temp = heap[1];
    heap[1]=heap[size];
    heap[size]=temp;
    //Decrementing the size
    size--;
    //placing the first element at it correct position
    int i =1;
    while(i<size){
        int largest = i;
        if(2*i<=size && heap[largest]<heap[2*i]) largest=2*i;
        if(2*i+1<=size && heap[largest]<heap[2*i+1]) largest = 2*i+1;
        if(largest!=i ){
            int a = heap[largest];
            heap[largest]=heap[i];
            heap[i]=a;
            i=largest;
        }else{
            break;
        }
    }
    heapSort(heap,size);
}

int main(){
    vector<int> arr ={-1 ,100, 96 ,48, 58 ,59 };
    int size = arr.size()-1;
    cout<<"Before : ";
    print_heap(arr);
    heapSort(arr,size);
    cout<<"After : ";
    print_heap(arr);
}