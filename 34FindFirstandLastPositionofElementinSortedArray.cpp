/* Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

class Solution {
public:
    
    // int binarysearch(vector<int> &nums, int start, int end, int target){
    //     if(start > end){
    //         return -1;
    //     }
    //     int mid = (start + end)/2;
    //     if(nums[mid]==target)
    //         return mid;
    //     if(nums[mid] < target)
    //         return binarysearch(nums, mid+1, end, target);
    //     return binarysearch(nums, start, mid-1, target);
    // }
    int lower_bound(vector<int> nums, int target){
        int s = 0, e = nums.size()-1, m = 0, ans = -1;
        while(s<=e){
            m = s+ (e-s)/2;
            if(nums[m]==target){
                ans = m;
                e = m-1;
            }else if(nums[m] < target){
                s = m + 1;
            }else{
                e = m-1;
            }
        }
        return ans;
    }
    int upper_bound(vector<int> nums, int target){
        int s = 0, e = nums.size()-1, m = 0, ans = -1;
        while(s<=e){
            m = s + (e-s)/2;
            if(nums[m]==target){
                ans = m;
                s = m+1;
            }else if(nums[m] < target){
                s = m+1;
            }else{
                e = m-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return {-1, -1};
        int l = lower_bound(nums, target);
        if(l==-1)
            return {-1,-1};
        
        int r = upper_bound(nums, target);
        return {l,r};
//         int ans = binarysearch(nums, 0, nums.size()-1, target);
//         if(ans==-1){
//             return {-1,-1};
//         }
//         int left = ans, right = ans;
//         while(left>=0 && nums[left]==nums[ans])
//             left--;
//         while(right<n && nums[right]==nums[ans])
//             right++;
        
//         return {left+1, right-1};
    }
};