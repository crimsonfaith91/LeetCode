class Solution {
public:
    bool isMatch(string s, string p) {
        int s_n = s.size(), p_n = p.size();
        
        vector<vector<bool>> dp(s_n + 1, vector<bool>(p_n + 1, false));
        dp[0][0] = true;
        
        for(int i = 0; i <= s_n; i++) {
            for(int j = 1; j <= p_n; j++) {
                if(j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (dp[i - 1][j]) && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));    
                }
                else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        
        return dp[s_n][p_n];
    }
};