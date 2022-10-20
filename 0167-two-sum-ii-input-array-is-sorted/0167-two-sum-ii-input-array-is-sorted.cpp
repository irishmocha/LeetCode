class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lower = 0;
        int upper = numbers.size() - 1;
        
        vector<int> answer;
        while (lower < upper) {
            if (numbers[lower] + numbers[upper] == target) {
                answer.emplace_back(lower + 1);
                answer.emplace_back(upper + 1);
            }
            
            if (numbers[lower] + numbers[upper] > target) {
                --upper;
            }
            else {
                ++lower;
            }
        }
        
        return answer;
    }
};