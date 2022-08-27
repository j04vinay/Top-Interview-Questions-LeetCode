/* Given a string s, return the longest palindromic substring in s.
*/


class Solution {
public:
    string longestPalindrome(string s) {
        
        /* Method 1 : Efficient method 
        This question is based on dynamic programming 
        Here we are first checking for right matching word 
        then left with current 
        then check for the matching element of indexes left and right
        And keep track of start index
        */
        int start = 0, ans = 1, n = s.length();
        
        for(int i=0; i<n; i++){
            int low = i-1, high = i+1;
            
            while(high<n && s[high]==s[i]){high++;}
                
            
            while(low>=0 && s[low]==s[i]){low--;}
                
            
            while(low>=0 && high<n && s[low]==s[high]){
                low--;
                high++;
            }
            
            if(ans < (high-low-1)){
                ans = high - low - 1;
                start = low + 1;
            }
        }
        return s.substr(start, ans);
    }
};