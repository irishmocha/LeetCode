class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int answer = INT_MAX;
        
        int lower = 0;
        int sum = 0;
        for (int upper = 0; upper < nums.size(); ++upper) {
            sum += nums[upper];
            while (sum >= target) {
                answer = min(answer, upper - lower + 1);
                sum -= nums[lower++];
            }
        }
        
        return (answer != INT_MAX) ? answer : 0;
    }
};