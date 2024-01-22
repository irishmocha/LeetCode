class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool inc = true;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (inc != (nums[i] <= nums[i + 1])) {
                std::swap(nums[i], nums[i + 1]);
            }
            inc = !inc;
        }
    }
};
