#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
// find the rank of the element of an array 
vector<int>findRank(vector<int> &arr){
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(auto elem : arr){
        minheap.push(elem);
    }
    unordered_map<int,int> mp;
    vector<int> result(arr.size(),0);
    int count =0;
    while(!minheap.empty()){
        count++;
        mp[minheap.top()] = count;
        minheap.pop();
    }
    for(int i = 0;i<arr.size();i++){
        result[i]= mp[arr[i]];
    }return result;}
int main(){
    vector<int> testcase ={1, 5, 8, 15, 8, 25 ,9};
    cout<<"Testcase : ";
    for(auto ele : testcase){
        cout<<ele << " ";
    }cout<<endl;
    vector <int> result = findRank(testcase);
    cout<<"Result : ";
    for(auto ele : result){
        cout<<ele << " ";
    }cout<<endl;
}