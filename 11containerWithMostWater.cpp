/* You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of 
the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, 
such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, n = height.size();
        
        // Method 1: Naive approach of complexity O(n*n)
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         ans = max(ans, min(height[i],height[j])*(j-i));
        //     }
        // }
        
        // Method 2 : Efficient way of complexity O(n)
        int start = 0, last = n-1;
        while(start<last){
            ans = max(ans, min(height[start], height[last])*(last-start));
            if(height[start]>height[last])
                last--;
            else
                start++;
        }
        return ans;
    }
};