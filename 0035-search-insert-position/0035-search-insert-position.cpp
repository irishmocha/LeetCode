class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        
        int position;
        while (lower <= upper) {
            position = lower + ((upper - lower) / 2);
            if (nums[position] == target) {
                return position;
            }
            
            if (nums[position] < target) {
                lower = position + 1;
            }
            else {
                upper = position - 1;
            }
        }
        
        return lower;
    }
};