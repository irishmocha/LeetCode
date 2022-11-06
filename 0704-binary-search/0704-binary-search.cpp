class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index;
        int lower = 0;
        int upper = nums.size() - 1;
        
        while (lower <= upper) {
            index = (lower + upper) / 2;
            if (nums[index] == target) return index;
            if (nums[index] < target) lower = index + 1;
            else upper = index - 1;
            
        }
        return -1;
    }
};