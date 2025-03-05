#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This function will find whether the provided dist is valid or not
bool ispossibleDist(vector<int> position, int cow, int dist)
{
    int lastposition =0;
    int counter = 1;
    bool ispossible =true;
    for(int i=1;i<position.size();i++){
        if(position[i]-position[lastposition]>=dist){
            counter++;
            lastposition=i;
        }
    }

    if(counter<cow){
        ispossible=false;
    }
    return ispossible;
}

//This function will find the max(min dist between two cows)
int MinDist(vector<int> &position, int cows)
{
    int ans=1;
    sort(position.begin(), position.end());
    int minNum = INT_MAX, maxNum = INT_MIN;
    for (int i = 0; i < position.size(); i++)
    {
        minNum = min(minNum, position[i]);
        maxNum = max(maxNum, position[i]);
    }

    int start = 1;
    int end = maxNum - minNum;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if(ispossibleDist(position,cows,mid)){
            ans=max(mid,ans);
            start =mid+1;
        }else{
            end=mid-1;
        }
    }

    return ans;
}

//Time complexity : O(nlogn) + O(nlog(max-min))
//space Complexity : O(1)
int main()
{
    vector<int> test = {1,2,8,4,9};
    int cows =3;
    cout<<"Answer : "<<MinDist(test , cows);
    return 0;
}