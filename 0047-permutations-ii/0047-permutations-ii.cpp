class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> curr;
        unordered_map<int, int> counter;
        for (auto x : nums) ++counter[x];
        generatePermutations(counter, curr, output, size(nums));
        return output;
    }
    
    void generatePermutations(unordered_map<int, int>& counter, vector<int>& curr, vector<vector<int>>& output, int n) {
        if (size(curr) == n) {
            output.emplace_back(curr);
            return;
        }
        for (auto [key, value] : counter) {
            if (value == 0) continue;
            curr.emplace_back(key); --counter[key];
            generatePermutations(counter, curr, output, n);
            curr.pop_back(); ++counter[key];
        }
    }
};