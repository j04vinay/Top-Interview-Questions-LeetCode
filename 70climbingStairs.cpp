/* You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n,-0);
        for(int i=0;i<n;i++){
            if(i==1) dp[i] = 2;
            else if(i==0) dp[i] = 1;
            else
                dp[i] += dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};