class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0, lower = 0;
        // 10, 5, 2, 6
        for (int upper = 0; upper < nums.size(); ++upper) {
            prod *= nums[upper];
            while (prod >= k)  {
                prod /= nums[lower++];
            }
            ans += upper - lower + 1;
        }
        return ans;
    }
};