class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 1
        stable_partition(nums.begin(), nums.end(), [](int n) { return n != 0; });
        
        /* 2.
        Runtime: 113 ms, faster than 11.61% of C++ online submissions for Move Zeroes.
        Memory Usage: 19.3 MB, less than 57.74% of C++ online submissions for Move Zeroes.
        */
//         int count = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == 0) {
//                 count++;
//                 // deleting the element from vector
//                 nums.erase(nums.begin() + i);
//                 i--;
//             }
//         }

//         for (int i = 0; i < count; i++) {
//             // inserting the zero into vector
//             nums.push_back(0);
//         }
        
    }
};