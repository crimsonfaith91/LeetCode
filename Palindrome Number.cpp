class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        int d = 1;
        
        while(x / d >= 10) 
            d *= 10;
        
        while(x) {
            if(x / d != x % 10)
                return false;
            
            x = x % d / 10;
            d /= 100;
        }
        
        return true;
    }
};