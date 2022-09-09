/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), c1 = 0, c2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) c1++;
            else if(nums[i]==1) c2++;
        }
        int i=0;
        for(;i<c1;i++) nums[i] = 0;
        for(;i<c1+c2;i++) nums[i] = 1;
        for(;i<n;i++) nums[i] = 2;
        // map<int,int>mymap;
        // for(int i=0;i<nums.size();i++)
        // {
        //     ++mymap[nums[i]];
        // }
        //  nums.clear();
        // for(auto e:mymap)
        // {
        //     while(e.second!=0)
        //     {
        //         nums.push_back(e.first);
        //         --e.second;
        //     }
        // }
    }
};