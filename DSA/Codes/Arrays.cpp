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
/*
Question 3: Sort Colors (https://leetcode.com/problems/sort-colors/)
Brute Force is to take a count of the number of 0's, 1's and 2's and then update the array with the count of 0's, 1's and 2's.
and then return the updated array.

Better Approach: Dutch National Flag Algorithm
1. Take 3 pointers low, mid and high.
2. low pointer is used to store the index of the 0's.   
3. mid pointer is used to store the index of the 1's.
4. high pointer is used to store the index of the 2's.      
5. If the mid pointer is pointing to 0 then swap the mid and low pointer and increment the mid and low pointer.
6. If the mid pointer is pointing to 1 then increment the mid pointer.      
7. If the mid pointer is pointing to 2 then swap the mid and high pointer and decrement the high pointer.
8. Continue the process till the mid pointer is less than or equal to the high pointer.
9. Return the updated array.

*/

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    /*
    Isko aise samjho ki low se mid tak 0's honge, mid se high tak 1's honge and high se end tak 2's honge.
    Understand the concept of low, mid and high pointers, like low to mid will have 0's, mid to high will have 1's and high to end will have 2's.
    */
    while(mid<=high){
        if(nums[mid] == 0){
            swap(nums[mid],nums[low]);
            mid++;low++;
        }

        else if(nums[mid] == 1) mid++;

        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}

/*
Question 4: Majority Element (https://leetcode.com/problems/majority-element/)
cONCEPT: Boyer-Moore Voting Algorithm
1. Take 2 variables candidate and count.    
2. Initialize the candidate with the first element of the array and count with 1.
3. Traverse the array and check if the element is equal to the candidate then increment the count.
4. If the element is not equal to the candidate then decrement the count.  
5. If the count is 0 then update the candidate with the current element and count with 1.
6. Return the candidate.    
*/



/*
Question 5: Kedane's Algorithm (https://leetcode.com/problems/maximum-subarray/)
Brute Force is to take 2 loops and check for all the subarrays and check the sum of the subarray.   
and then return the maximum sum of the subarray.
Best Approach: Kedane's Algorithm  
1. Take 2 variables max_sum and curr_sum.
2. Initialize both the variables with the first element of the array.
3. Traverse the array and check if the current element is greater than the sum of the current element and the current sum then update the current sum with the current element.
4. If the current sum is greater than the maximum sum then update the maximum sum with the current sum.
*/

int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum=nums[0];
        int curr_sum=nums[0];
        for(int i=1;i<n;i++)
        {
            curr_sum=max(nums[i],curr_sum+nums[i]);
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
}

int main()
{
    vector<int> v;

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}