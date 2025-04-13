#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int largestInteger(vector<int>& nums, int k) {
    unordered_map<int,int> hashmap;
    int result =-1;
    for(int i=0;i<nums.size();i++){
            for(int j=i;j<=i+k-1 && i+k-1<nums.size();j++){
                if(hashmap.find(nums[j])!=hashmap.end()){
                    hashmap[nums[j]]=hashmap[nums[j]]+1;
                }else{
                    hashmap[nums[j]]=1;
                }
            }
        
    }
    for(const auto & pair:hashmap){
        cout<<pair.first<<" | "<<pair.second<<endl;
        // if(pair.second==1){
        //     result=max(result,pair.first);
        // }
    }
    return result;
}

int main(){
    vector<int> test = {3,9,2,1,7};
    int k =3;
    largestInteger(test,k);
}