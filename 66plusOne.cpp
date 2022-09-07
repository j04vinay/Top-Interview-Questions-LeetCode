/* You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, n = digits.size();
        int x = digits[n-1]+1;
        carry = x/10;
        x = x%10;
        if(!carry){
            digits[n-1] = x;
            return digits;
        }
        vector<int> ans;
        ans.push_back(x);
        
        for(int i=n-2; i>=0; i--){
            x = digits[i]+carry;
            carry = x/10;
            x = x%10;
            ans.push_back(x);
        }
        if(carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};