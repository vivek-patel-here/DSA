#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<long long> kSum(nums1.size(), 0);

    for (int i = 0; i < nums1.size(); i++)
    {

        vector<int> lessIndex;
        for (int j = 0; j < nums1.size(); j++)
        {
            if (nums1[j] < nums1[i])
            {
                lessIndex.push_back(j);
            }
        }

        if (lessIndex.size() == 0)
        {
            kSum[i] = 0;
            continue;
        }

        for (int m = 0; m < lessIndex.size(); m++)
        {
            lessIndex[m] = nums2[lessIndex[m]];
        }

        sort(lessIndex.begin(), lessIndex.end());
        int m = lessIndex.size();
        int size = min(m,k);
        long long sum = 0;
        while (size > 0)
        {
            sum += lessIndex[lessIndex.size() - size];
            size--;
        }

        kSum[i] = sum;
    }
    return kSum;
}

int main()
{
    vector<int> nums1 = {2, 2, 2, 2};
    vector<int> nums2 = {3, 1, 2, 3};
    int k = 2;
    vector<long long> result = findMaxSum(nums1, nums2, k);
}