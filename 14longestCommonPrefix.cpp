/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
 
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        int minlen = strs[0].length(), n = strs.size();
        for(int i=0; i<minlen; i++){
            bool flag = true;
            for(int j = 1; j<n; j++){
                if(strs[0][i]!=strs[j][i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans += strs[0][i];
            else
                break;
        }
        return ans;
    }
};