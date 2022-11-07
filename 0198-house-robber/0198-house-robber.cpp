class Solution {
public:
    
    int rob(vector<int>& nums) {
        vector<int> memo(100, -1);
        return robFrom(0, nums, memo);
    }
    
    int robFrom(int i, vector<int>& nums, vector<int>& memo) {
        if (i >= nums.size()) {
            return 0;
        }
        if (memo[i] > -1) {
            return memo[i];
        }
        int ans = max(robFrom(i + 1, nums, memo), robFrom(i + 2, nums, memo) + nums[i]);
        return memo[i] = ans;
    }
};