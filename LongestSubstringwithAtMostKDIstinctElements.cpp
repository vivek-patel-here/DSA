#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Longest Substring with At Most K distinct character 
string LongestSubstr(string s,int k){
    string maxSubstr = "";
    int lptr=0,rptr=0;
    vector<int> freq(26,0);
    int uniques=0;
    while(rptr<s.length()){
       if(freq[s[rptr]-'a']==0) uniques++;
       freq[s[rptr]-'a']+=1;

       while(uniques>k){
        freq[s[lptr]-'a']-=1;
        if(freq[s[lptr]-'a']==0) uniques--;
        lptr++;
       }
       if(maxSubstr.length()<rptr-lptr+1){
        maxSubstr=s.substr(lptr,rptr-lptr+1);
       }
       rptr++;
    }
    return maxSubstr;
}

int main(){
    string test = "aaabbccd";
    int k=2;
    string result = LongestSubstr(test,k);
    cout<<"Longest Substring with at most k distinct Character : "<<result;
}