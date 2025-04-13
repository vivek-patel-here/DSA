#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int convertIntoNumber(string s)
{
    if (s.length() == 0)
        return 0;
    if (s.length() == 1)
    {
        return (int)s[0] - 48;
    }
    int num = (int)s[s.length()-1] - 48;
    return convertIntoNumber(s.substr(0,s.length()-1)) * 10 + num;
}

int main()
{
    string testcase = "456";
    cout<<convertIntoNumber(testcase);
}