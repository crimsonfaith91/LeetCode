class Solution {
public:
    string intToRoman(int num) {
        string ans;
        
        int d[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        for(int i = 0; num; i++) {
            int q = num / d[i];
            num %= d[i];
                
            while(q--) ans.append(romans[i]);
        }
        
        return ans;
    }
};