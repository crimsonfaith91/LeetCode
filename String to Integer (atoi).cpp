class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        if(n == 0) return 0;
        
        int ans = 0, i = 0;
        bool is_neg = false;
        
        while(str[i] == ' ') i++;
        
        if(i < n && (str[i] == '+' || str[i] == '-')) {
            is_neg = str[i] == '-';
            i++;
        }
        
        while(i < n) {
            if(!(str[i] >= '0' && str[i] <= '9')) break;
            
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && ((str[i] - '0') > INT_MAX % 10))) {
                return is_neg ? INT_MIN : INT_MAX;
            }
            
            ans = ans * 10 + str[i] - '0';
            i++;
        }
        
        return is_neg ? -ans : ans;
    }
};