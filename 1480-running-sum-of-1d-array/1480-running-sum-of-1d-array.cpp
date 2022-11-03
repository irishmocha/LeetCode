class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> answer;
        for (int i = 0, acc = 0; i < nums.size(); acc += nums[i], ++i) {
            answer.push_back(acc + nums[i]);
        }
        return answer;
    }
};