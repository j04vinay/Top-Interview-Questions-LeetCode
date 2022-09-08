/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = nums[0], t= 0;
        for(int i=0;i<n;i++){
            t += nums[i];
            if(sum < t) sum = t;
            if(t < 0) t = 0;
        }
        return sum;
    }
};