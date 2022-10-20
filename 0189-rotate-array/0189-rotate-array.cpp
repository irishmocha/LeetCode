
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin()+k);
        // reverse(nums.begin()+k, nums.end());
        vector<int> t = nums;
        for (int i = 0; i < nums.size(); ++i) {
            nums[(i + k) % nums.size()] = t[i];
        }
        
    }
};