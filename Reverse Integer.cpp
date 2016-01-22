class Solution {
public:
    int reverse(int x) {
        bool isNeg = x < 0;
                
        if(isNeg) {
            x = -x;
            
            if(x < 0) return 0; //overflow
        }
        
        int ans = 0;
        
        while(x) {
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && x % 10 > INT_MAX % 10)) return 0; //overflow
            
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        
        return isNeg ? -ans : ans;
    }
};