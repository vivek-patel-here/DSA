#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool rotateString(string s, string goal) {
    if(s.length()!=goal.length()) return false;
    s=s+s;
    int lptr =0;
    bool result =false;
    while(lptr<s.length()){
        if(s.substr(lptr,goal.length())==goal){
            result=true;
        }
        lptr++;
    }
    return result;

}


int main(){
    string s = "abcde", goal = "cdefab";
    cout<<rotateString(s,goal);
    return 0;
}