#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{ 
    //**************************MAX HEAP***************************
    priority_queue<int> maxheap;
    maxheap.push(5);
    maxheap.push(4);
    maxheap.push(9);
    maxheap.push(10);
    maxheap.push(7);
    maxheap.push(8);
    //print the heap
    cout << "MaxHeap : [ ";
    while (!maxheap.empty()){ cout<<maxheap.top()<<" "; maxheap.pop();}
    cout << "]"<<endl;
    //**************************MIN HEAP***************************
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(5);
    minheap.push(4);
    minheap.push(9);
    minheap.push(10);
    minheap.push(7);
    minheap.push(8);
    //print the heap
    cout << "MinHeap : [ ";
    while (!minheap.empty()){cout<<minheap.top()<<" ";minheap.pop();}
    cout << "]"<<endl;
}