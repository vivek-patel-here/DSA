#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printArray(vector<int> &arr)
{
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]" << endl;
}

    int missing(vector<int> &arr,int k){
    vector<int> missing;
    int maxElem =*max_element(arr.begin(),arr.end()); //O(n)
    int indx=0;
    int elem=1;
    while(indx<arr.size()){
        if(elem==arr[indx]){
            indx++;
            elem++;
        }else{
            missing.push_back(elem);
            elem++;
        }
    }
    int result =0;
        if(k-1<missing.size()){
            result=missing[k-1];
        }else{
            k=k-missing.size();
            result=maxElem+k;
        }

        return result;
}

int main(){
    vector<int> arr = {1,2,3,4};
    int result =missing(arr,5);
    cout<<result;

    return 0;
}