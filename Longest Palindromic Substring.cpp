class Solution {
public:
    string searchLongestPalin(string &s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans;
        
        int n = s.size();
        
        if(n == 0) return ans;
        
        for(int i = 0; i < n; i++) {
            string curLongest = searchLongestPalin(s, i, i);
            
            if(curLongest.size() > ans.size()) {
                ans = curLongest;
            }
            
            curLongest = searchLongestPalin(s, i, i + 1);
            
            if(curLongest.size() > ans.size()) {
                ans = curLongest;
            }
        }
        
        return ans;
    }
};