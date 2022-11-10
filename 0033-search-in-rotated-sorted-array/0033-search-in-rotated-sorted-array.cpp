class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        
        while (lower <= upper) {
            int i = lower + (upper - lower) / 2;
            if (nums[i] == target) {
                return i;
            }
            
            if (nums[lower] <= nums[i]) {
                if (nums[lower] <= target && target < nums[i]) {
                    upper = i - 1;
                }
                else {
                    lower = i + 1;
                }
            }
            else {
                if (nums[i] < target && target <= nums[upper]) {
                    lower = i + 1;
                }
                else {
                    upper = i - 1;
                }
            }
        }
        
        return -1;
    }
};