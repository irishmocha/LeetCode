class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0;
        int y = matrix[0].size() - 1;
        while (x < matrix.size() && y > -1) {
            if (matrix[x][y] == target) return true;
            matrix[x][y] < target ? ++x : --y;
        }

        return false;
    }
};