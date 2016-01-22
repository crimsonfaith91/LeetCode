class Solution {
public:
    string convert(string s, int nRows) {
        if(!s.length() || nRows < 2) return s;
        
        string ans;
        vector<string> strs(nRows, string());
        int count = 0;
        bool down = true;
        
        for(int i = 0; i < s.length(); i++) {            
            strs[count].push_back(s[i]);
            
            if(i > 0 && (count == nRows - 1 || count == 0)) {
                down = !down;
            }
            
            if(down) count++;
            else count--;
        }
        
        for(string s : strs) {
            ans.append(s);
        }
        
        return ans;
    }
};