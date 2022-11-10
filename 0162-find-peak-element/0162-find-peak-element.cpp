class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size() - 1;
        while (lower < upper) {
            int mid = lower + (upper - lower) / 2;
            if (nums[mid] < nums[mid + 1]) 
                lower = mid + 1;
            else upper = mid;
        }
        
        return lower;
    }
};