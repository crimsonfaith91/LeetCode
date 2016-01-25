class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        
        int n = strs.size();
        if(n == 0) return ans;
        
        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 1; j < strs.size(); j++) {
                if(i == strs[j].size() || strs[j][i] != strs[0][i]) return ans;    
            }
            
            ans.push_back(strs[0][i]);
        }
        
        return ans;
    }
};