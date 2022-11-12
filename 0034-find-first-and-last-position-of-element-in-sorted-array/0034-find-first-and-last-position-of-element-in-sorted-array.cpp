class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        
        vector<int> answer(2, -1);
        while (lower <= upper) {
            int i = lower + (upper - lower) / 2;
            if (target > nums[i]) {
                lower = i + 1;
            }
            else {
                if (nums[i] == target) {
                    answer[0] = i;
                }
                upper = i - 1;
            }
        }
        
        lower = 0;
        upper = nums.size() - 1;
        while (lower <= upper) {
            int i = lower + (upper - lower) / 2;
            if (target < nums[i]) {
                upper = i - 1;
            }
            else {
                if (nums[i] == target) {
                    answer[1] = i;
                }
                lower = i + 1;
            }
        }
        
        return answer;
    }
};