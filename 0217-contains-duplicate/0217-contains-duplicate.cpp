class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int t = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return t != nums.size();
    }
};