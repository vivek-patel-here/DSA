#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int upperBound(vector<int> list , int num){
    int ans=-1;
    int start = 0;
    int end= list.size()-1;
    if(num>list[list.size()-1]) return -1;
    while(start<=end){
        int mid = start +(end-start)/2;
        if(list[mid]<=num){
            start=mid+1;
        }else{
            ans=mid;
            end = mid-1;
        }
    }
    return ans;
}

int smallerEqual(vector<vector<int>> matrix , int num){
    int counter = 0;
    for(int i=0;i<matrix.size();i++){
        counter += upperBound(matrix[i],num);
    }
    return counter;
}

int matrixMedian(vector<vector<int>> mat){
    int reqCount =(mat.size()*mat[0].size())/2;
    int start=INT_MAX,end=INT_MIN;
    for(int i=0;i<mat.size();i++){
        start =min(start,mat[i][0]);
        end =max(end,mat[i][mat[0].size()-1]);
    }
    while(start<=end){
        int mid =start +(end-start)/2;
        if(smallerEqual(mat,mid)<=reqCount){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return start;

}

int main(){
    vector<vector<int>> temp ={{15,34,53},{7,7,7},{7,7,8}};
    cout<<matrixMedian(temp);
    return 0;
}
