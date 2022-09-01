/* There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

class Solution {
public:
    
    int binarySearch(vector<int> &nums, int start, int end, int target){
        if(start>end)
            return -1;
        int mid = (start+end)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[mid]>target)
            return binarySearch(nums, start, mid-1, target);
        return binarySearch(nums, mid+1, end, target);
    }
    int findPivotedIndex(vector<int> &nums, int start, int end){
        if(end<start)
            return -1;
        if(start==end)
            return start;
        int mid = (start+end)/2;
        if(mid < end && nums[mid]>nums[mid+1])
            return mid;
        if(mid > start && nums[mid]<nums[mid-1])
            return mid-1;
        if(nums[start]>=nums[mid])
            return findPivotedIndex(nums,start,mid-1);
        return findPivotedIndex(nums,mid+1,end);
    }
    int search(vector<int>& nums, int target) {
        int pivot = findPivotedIndex(nums, 0, nums.size()-1);
        //cout<<pivot<<endl;
        if(pivot==-1)
            return binarySearch(nums, 0, nums.size()-1, target);
        if(nums[pivot]==target)
            return pivot;
        if(nums[0]<=target)
            return binarySearch(nums, 0, pivot-1, target);
        return binarySearch(nums, pivot+1, nums.size()-1, target);
    }
};