#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int returnSum(vector<int> &vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return sum;
}

int CalReqDay(vector<int> &weights, int capacity)
{
    int load = 0;
    int days = 1;
    for (int i = 0; i < weights.size(); i++)
    {
       if(load+weights[i]>capacity){
        days++;
        load=weights[i];
       }else{
        load+=weights[i];
       }
    }
    
    return days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int start = *min_element(weights.begin(), weights.end());
    int end = returnSum(weights);
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int ReqDays = CalReqDay(weights, mid);
        if (ReqDays <= days)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}

int main()
{
    vector<int> temp = {3, 2, 2, 4, 1, 4};
    int result = shipWithinDays(temp, 3);
    cout << result;
    return 0;
}