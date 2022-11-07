class Solution {
private:
    void dfs(vector<vector<int>>& answer, vector<int> nums, int i) {
        if (i == nums.size()) {
            answer.push_back(nums);
        }
        
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            dfs(answer, nums, i + 1);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        dfs(answer, nums, 0);
        return answer;
    }
};