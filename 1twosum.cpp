/*
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.


Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        
        // Method 1 : naive approach
        /* For every i we are search an j where nums[i]+nums[j]==target,
        so we are using two loops which of time complexity O(n*n)
        */
        
        // int n = nums.size();
        // for(int i=0;i<n-1;i++){
        //     for(int j = i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target){
        //             ans[0] = i;
        //             ans[1] = j;
        //             break;
        //         }
        //     }
        // }
        
        // Method 2 : Using Hashmap
        /* Using hashmap we can reduce time complexity to O(n),
        in this for every nums[i] we are finding an element target-nums[i] 
        if this exist then we are return ans otherwise we are inserting nums[i]
        into hashmap
        */
        int n = nums.size();
        map<int, int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans[0] = mp[target-nums[i]];
                ans[1] = i;
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};