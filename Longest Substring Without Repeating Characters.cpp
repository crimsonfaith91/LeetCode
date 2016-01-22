class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        
        bool repeated[256] = {false};
        int start = 0;
        int n = s.length(); //"s.length() - start" does not work; "s.length() " must cast to integer
        
        for(int i = 0; i < n; i++) {
            if(repeated[s[i]]) {
                ans = max(ans, i - start);
                
                while(s[start] != s[i]) {
                    repeated[s[start]] = false;
                    start++;
                }
                
                start++;
            }
            else {
                repeated[s[i]] = true;
            }
        }
        
        return max(ans, n - start);
    }
};