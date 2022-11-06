class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lower = 0;
        int upper = numbers.size() - 1;
        
        int sum;
        vector<int> answer;
        while (lower < upper) {
            sum = numbers[lower] + numbers[upper];
            if (sum == target) {
                answer.emplace_back(lower + 1);
                answer.emplace_back(upper + 1);
            }
            
            if (sum > target) {
                --upper;
            }
            else {
                ++lower;
            }
        }
        
        return answer;
    }
};