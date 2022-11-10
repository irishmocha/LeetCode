class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int x = 0;
        int y = n - 1;
			
        while (x < matrix.size() && y > -1) {
            if (target == matrix[x][y]) return true;
            matrix[x][y] < target ? ++x : --y;
        }

        return false;
    }
};