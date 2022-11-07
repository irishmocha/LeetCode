class Solution {
private:
    void permute(vector<vector<int>>& answer, vector<int> nums, int i) {
        if (i == nums.size()) {
            answer.push_back(nums);
        }
        
        for (int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            permute(answer, nums, i + 1);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        permute(answer, nums, 0);
        return answer;
    }
};