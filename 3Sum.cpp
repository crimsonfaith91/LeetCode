class Solution {
public:
    /*
    //recursive
    void threeSumRecur(vector<int> &num, vector<vector<int>> &ans, vector<int> &sumToZero, int index) {
        if(sumToZero.size() == 3) {           
            if(sumToZero[0] + sumToZero[1] + sumToZero[2] == 0) {
                ans.push_back(sumToZero);
            }
            
            return;
        }
        
        for(int i = index; i < num.size(); i++) {
            sumToZero.push_back(num[i]);
            threeSumRecur(num, ans, sumToZero, i + 1);
            sumToZero.pop_back();
            
            while(i < num.size() - 1 && num[i] == num[i + 1]) {
                i++;
            }
        }
    }

    vector<vector<int> > threeSum(vector<int> &num) {                        
        sort(num.begin(), num.end());
        
        vector<vector<int>> ans;
        vector<int> sumToZero;
        
        threeSumRecur(num, ans, sumToZero, 0);
        
        return ans;
    }
    */
    
    //Time Complexity: O(n^2), Space Complexity: O(1)
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ans;
        
        if(num.size() < 3) return ans;    
        
        sort(num.begin(), num.end());
        
        int n = num.size();
        
        for(int i = 0; i < n - 2; i++) {
            int begin = i + 1, end = n - 1;
            
            while(begin < end) {
                int sum = num[i] + num[begin] + num[end];
                if(!sum) {
                    ans.push_back({num[i], num[begin], num[end]});
                    begin++;
                    end--;
                    
                    while(begin < end && num[begin] == num[begin - 1]) begin++;
                    while(begin < end && num[end] == num[end + 1]) end--;
                }
                else if(sum < 0) {
                    begin++;
                }
                else {
                    end--;
                }
            }
            
            while(i < n - 3 && num[i] == num[i + 1]) {
                i++;
            }
        }
        
        return ans;
    }
};