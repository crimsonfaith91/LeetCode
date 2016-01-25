class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.size() < 2) return 0;
        
        int ans = INT_MIN;
        int begin = 0, end = height.size() - 1;
        
        while(begin < end) {
            int curArea = min(height[begin], height[end]) * (end - begin);
            
            ans = max(ans, curArea);
            
            height[begin] <= height[end] ? begin++ : end--;
        }
        
        return ans;
    }
};