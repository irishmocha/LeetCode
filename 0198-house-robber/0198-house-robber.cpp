class Solution {
public:
//     int rec(vector<int>& nums, int i, vector<int>& dp) {
//         if (i >= nums.size()) {
//             return 0;
//         }
//         if (dp[i] != -1) {
//             return dp[i];
//         }
        
//         return dp[i] = max(rec(nums, i + 1, dp), nums[i] + rec(nums, i + 2, dp));
//     }

    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size() + 1, -1);
        
        // return rec(nums, 0, dp);
      
      
      
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        return dp[nums.size()-1];
        
  }
};