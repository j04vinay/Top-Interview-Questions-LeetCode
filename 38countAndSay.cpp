/* The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans = "1", t = "";
        
        for(int i=0;i<n-1;i++){
            t = "";
            int len = ans.length();
            for(int j=0;j<len;j++){
                int count = 1;
                while(j<len-1 && ans[j]==ans[j+1]){
                    count++;j++;
                }
                t += to_string(count);
                t += ans[j];
            }
            ans = t;
            // cout<<ans<<endl;
        }
        return ans;
    }
};