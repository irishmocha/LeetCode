class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> u;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (u.find(complement) != u.end()) {
                return vector<int>{u[complement], i};
            }
            u[nums[i]] = i;
        }
        
        return vector<int>{};
    }
};