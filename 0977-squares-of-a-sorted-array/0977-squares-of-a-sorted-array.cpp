class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size() - 1;
        int index = nums.size() - 1;
        
        vector<int> answer(nums.size(), -1);
        while (lower <= upper) {
            if (abs(nums[lower]) <= abs(nums[upper])) {
                answer[index--] = nums[upper] * nums[upper];
                --upper;
            }
            else {
                answer[index--] = nums[lower] * nums[lower];
                ++lower;
            }
            // --index;
        }
        
        return answer;
    }
};