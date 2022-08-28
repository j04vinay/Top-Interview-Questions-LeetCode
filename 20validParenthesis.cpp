/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else if(!st.empty()){
                if((s[i]==')' and st.top()=='(') || (s[i]==']' and st.top()=='[') || 
                   (s[i]=='}' and st.top()=='{')){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};