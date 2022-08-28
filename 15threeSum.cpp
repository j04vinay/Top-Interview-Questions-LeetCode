/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /* Method 1 : Efficient method
        Here I had fixed one variable fix and then using two pointers
        For getting unique triplet we are skiping for the same value
        */
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size(), l, r;
        for(int i=0; i<n-2; i++){
            if(i==0 || i>0 && nums[i]!=nums[i-1]){
                l = i+1;
                r = n-1;
                while(l<r){
                    // cout<<i<<" "<<l<<" "<<r<<endl;
                    if(nums[i]+nums[l]+nums[r] == 0){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        // cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<endl;
                        ans.push_back(temp);
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;
                        l++; r--;
                    }else if(nums[i]+nums[l]+nums[r] > 0){
                        r--;
                    }else{
                        l++;
                    } 
                }
            }
        }
        return ans;
    }
};