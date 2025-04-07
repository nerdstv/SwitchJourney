#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

#include <numeric>
using namespace std;

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
Question 4 and 5: Majority Element I and II(https://leetcode.com/problems/majority-element/ , https://leetcode.com/problems/majority-element-ii/)
cONCEPT: Boyer-Moore Voting Algorithm:
1. This algorithm is used to find the majority element in the array in both the questions.
2. In the first question, the majority element is the element that appears more than n/2 times.
3. In the second question, the majority element is the element that appears more than n/3 times.
4. The algorithm is used to find the majority element in the array.

THe Logic of the Algorithm is:
1. Take 2 variables candidate and count.
2. Initialize the candidate with the first element of the array and count with 1.
3. Traverse the array and check if the current element is equal to the candidate then increment the count.
4. If the current element is not equal to the candidate then decrement the count.
5. If the count is 0 then update the candidate with the current element and count with 1.
6. Traverse the array again and check the frequency of the candidate element.
7. If the frequency is greater than n/2 then return the candidate element.
8. If the frequency is greater than n/3 then return the candidate element.
9. If the frequency is not greater than n/2 then return -1.
10. If the frequency is not greater than n/3 then return -1.

In hind:
1. 2 variables lo candidate and count lelo.
2. Candidate ko first element se initialize karo and count ko 1 se.
3. Array traverse karo and check karo ki current element candidate ke equal hai ya nahi.
4. Agar current element candidate ke equal hai to count ko increment karo.  
5. Agar current element candidate ke equal nahi hai to count ko decrement karo.
6. Agar count 0 ho gaya to candidate ko current element se update karo and count ko 1 se update karo.
7. Fir se array traverse karo and check karo ki candidate element ka frequency kitna hai.
8. Agar frequency n/2 se jyada hai to candidate element return karo.
9. Agar frequency n/3 se jyada hai to candidate element return karo.
10. Agar frequency n/2 se jyada nahi hai to -1 return karo.
11. Agar frequency n/3 se jyada nahi hai to -1 return karo.  

Note: In the second question, there can be multiple majority elements so we have to check the frequency of the candidate element.
To check the frequency of the candidate element, we have to traverse the array again.

*/
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n = nums.size();
            int ans = nums[0];
            int count = 1;
    
            for(int i = 1; i < n; i++){
    
                if(count == 0){
                    count = 1;
                    ans = nums[i];
                }
                else if(nums[i] == ans) count++;
                else {
                    //ans = nums[i];
                    count --; 
                }
            }
    
            return ans;
            
        }
    };

    
class Solution {
    public:
        vector<int> majorityElementII(vector<int>& nums) {
            int n = nums.size();
            
            int maj1    = NULL;
            int count1 = 0;
    
            int maj2    = NULL;
            int count2 = 0;
            int freq = floor(n/3);
            
            for(int i = 0; i<n; i++) {
                if(nums[i] == maj1)
                    count1++;
                else if(nums[i] == maj2)
                    count2++;
                else if(count1 == 0) {
                    maj1 = nums[i];
                    count1 = 1;
                } else if(count2 == 0) {
                    maj2 = nums[i];
                    count2 = 1;
                } else {
                    count1--;
                    count2--;
                }
            }
            
            vector<int> result; //because atmost two elements can occur more than ⌊ n/3 ⌋ in an array of length n
            count1 = 0;
            count2 = 0;
            for(int num:nums) {
                if(num == maj1)
                    count1++;
                else if(num == maj2)
                    count2++;
            }
            if(count1 > floor(n/3))
                result.push_back(maj1);
            if(count2 > floor(n/3))
                result.push_back(maj2);
            return result;
    
    
        }
    };


/*
Question 6: Kedane's Algorithm (https://leetcode.com/problems/maximum-subarray/)
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

/*Question 7: Best Time to Buy and Sell Stock (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)(DP)
Algo:
1. Take 2 variables min_price and max_profit.
2. Initialize min_price with the first element of the array and max_profit with 0.
3. Traverse the array and check if the current element is less than the min_price then update the min_price with the current element.
4. If the current element is greater than the min_price then update the max_profit with the difference of the current element and the min_price.
5. Return the max_profit.
 In hindi:
1. 2 variables lo min_price and max_profit lelo.
2. Min_price ko first element se initialize karo and max_profit ko 0 se.
3. Array traverse karo and check karo ki current element min_price se chota hai ya nahi.
4. Agar current element min_price se chota hai to min_price ko current element se update karo.
5. Agar current element min_price se bada hai to max_profit ko current element aur min_price ka difference se update karo.
6. Max_profit ko return karo.
*/
//Please do dry run once to understand the logic.
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int ans = 0;
    int mini = prices[0];
    for(int i = 1; i<n; i++){
        int cost = prices[i] - mini;// buy kar rahe hai
        mini = min(mini, prices[i]); // sell kar rahe hai
        ans = max(ans, cost);// profit nikal rahe hai
    }

    return ans;
}
//We will again discuss this in the DP section.

/*
Question 8: 2149. Rearrange Array Elements by Sign (https://leetcode.com/problems/rearrange-array-elements-by-sign/)
Watch:https://www.youtube.com/watch?v=cSG2bzAuLGU
*/

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();

    vector<int> result(n);

    int pi = 0;
    int ni = 1;

    for(int &num : nums) {
        if(num > 0){
            result[pi] = num;
            pi+=2;
        }else{
            result[ni] = num;
            ni+=2;
        }
    }
    return result;
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