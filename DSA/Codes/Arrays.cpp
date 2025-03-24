#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

#include <numeric>
using namespace std;

/*DAY 1*/
//Question 1: Longest Subarray with Sum K (https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/)
/*
Brute Force is to take 2 poiunters and check for all the subarrays and check if the sum is equal to k or not. 
and then return the maximum length of the subarray.

BETTER APPROACH:
1. Take a prefix sum array and then check for the sum of the subarray by taking the difference of the prefix sum array.
2. If the difference is equal to k then update the maximum length of the subarray.  
3. Use a hashmap to store the prefix sum and the index of the prefix sum.
4. If the difference is equal to k then update the maximum length of the subarray.  
5. If the prefix sum is not present in the hashmap then store the prefix sum and the index of the prefix sum.
6. Return the maximum length of the subarray.   


*/
int longestSubarray(vector<int> &v, long long k)
{
    unordered_map<long long, int> mp;
    long long sum = 0;
    int max_len = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum == k)
        {
            max_len = i + 1;
        }
        if (mp.find(sum - k) != mp.end())
        {
            max_len = max(max_len, i - mp[sum - k]);
        }

        //Below code is used to store the prefix sum and the index of the prefix sum. It's important step.
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return max_len;
}

/*
Question 2: Two Sum (https://leetcode.com/problems/two-sum/)
Brute Force is to take 2 loops and check for all the pairs and check if the sum is equal to target or not.  
and then return the pair of the indices.
Better Approach:
1. Take a hashmap and store the element and the index of the element.   
2. Check if the difference of the target and the element is present in the hashmap or not.
3. If present then return the pair of the indices.

*/

vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]]=i;
        }
}

/*Day2 ====================================================================================================================*/


int main()
{
    vector<int> v;

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}