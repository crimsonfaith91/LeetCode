class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < numbers.size(); i++) {
            if(map.count(numbers[i])) {
                return {map[numbers[i]], i + 1};
            }
            
            map[target - numbers[i]] = i + 1;
        }
        
        throw invalid_argument("Invalid input!");
    }
};