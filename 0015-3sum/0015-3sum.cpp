class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            
            int lower = i + 1;
            int upper = nums.size() - 1;
            while(lower < upper) {
                int sum = nums[i] + nums[lower] + nums[upper];
                if (sum == 0) {
                    ans.push_back({nums[i] , nums[lower] , nums[upper]});
                    ++lower; --upper;
                    while (nums[lower] == nums[lower - 1] && lower < upper)
                        ++lower;
                    // while (nums[lower] == nums[upper + 1] && lower < upper)
                    //     --upper;
                }
                
                if (sum > 0) {
                    --upper;
                }
                else if (sum < 0) {
                    ++lower;
                }

            }
        }
        
        return ans;
    }
};