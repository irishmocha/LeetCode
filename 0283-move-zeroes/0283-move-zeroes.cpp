class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 1
        // stable_partition(nums.begin(), nums.end(), [](int n) { return n != 0; });
        
        //2
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                // deleting the element from vector
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        for (int i = 0; i < count; i++) {
            // inserting the zero into vector
            nums.push_back(0);
        }
        
    }
};