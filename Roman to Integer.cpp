class Solution {
public:
    int romanVal(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return 0;
        }
    }

    int romanToInt(string s) {
        int val = romanVal(s[0]);
        
        for(int i = 1; i < s.length(); i++) {
            if(romanVal(s[i]) > romanVal(s[i - 1])) {
                val += (romanVal(s[i]) - 2 * romanVal(s[i - 1]));
            }
            else {
                val += romanVal(s[i]);
            }
        }
        
        return val;
    }
};