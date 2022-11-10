class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int x = 0;
        int y = cols - 1;
			
        while (x < rows && y > -1) {
            int cur = matrix[x][y];
            if (cur == target) return true;
            if (target > cur) x++;
            else y--;
        }

        return false;
    }
};