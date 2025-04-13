#include <iostream>
#include <vector>
using namespace std;
vector<int> heap; // max heap

void print_heap()
{
    for (int i = 1; i < heap.size(); i++) cout << heap[i] << " ";
    cout << endl;
}

void insertHeap(int elem)
{
    if (heap.size() == 0) heap.push_back(0);
    heap.push_back(elem);
    int i = heap.size() - 1;
    while (i > 1 && heap[i] > heap[i / 2])
    {
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i = i / 2;
    }
    cout << elem << " inserted successfully!" << endl;
}

void deleteRoot(){
    if(heap.size()<=1) return; // This means our heap is empty
    int root = 1;
    //swaping the root node with the last node
    int temp = heap[root];
    heap[root]=heap[heap.size()-1];
    heap[heap.size()-1] = temp;
    //deleting the last node
    heap.pop_back();
    //Re-ordering the heap
    while(root<heap.size()-1){
        int leftChild = root*2;
        int rightChild = root*2+1;
        if(heap[leftChild]>heap[root]){
            int temp  =heap[leftChild];
            heap[leftChild] =heap[root];
            heap[root]=temp;
            root =leftChild;
        }else if(heap[rightChild]>heap[root]){
            int temp  =heap[rightChild];
            heap[rightChild] =heap[root];
            heap[root]=temp;
            root =rightChild;
        }else{
            break;
        }
    }
    cout<<"Node deleted successfully"<<endl;
}

int main(){
    insertHeap(5);
    insertHeap(6);
    insertHeap(7);
    print_heap(); //print heap
    insertHeap(8);
    insertHeap(9);
    insertHeap(5);
    print_heap(); //print heap

    deleteRoot();
    cout<<"After deletion " <<endl;
    print_heap(); //print heap

}