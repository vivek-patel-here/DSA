#include <iostream>
#include <vector>
using namespace std;

//function to check whether an array is min heap or not 
bool isMinHeap(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int leftElem =  2*i;
        int rightElem  =2*i+1;
        if(leftElem<arr.size() && arr[i]>arr[leftElem]) return false;
        if(rightElem<arr.size() && arr[i]>arr[rightElem]) return false;
    }
    return true;
}

int main(){
    vector<int> testcase={-1,100,95,96,96,95,9,49,87};
    cout<<"testcase 1 : "<<isMinHeap(testcase)<<endl;
    vector<int> testcase2={-1,7,8,16,92,69,48,56,100,101};
    cout<<"testcase 2 : "<<isMinHeap(testcase2)<<endl;


}