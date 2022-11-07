class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isIn(int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }
        return true;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y, int count, vector<vector<bool>>& visited) {
        int areaSize = 0;
        
        visited[x][y] = true;
        ++areaSize;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isIn(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
                areaSize += dfs(grid, nx, ny, areaSize, visited);
            }
        }
        
        return areaSize;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int t = dfs(grid, i, j, 0, visited);
                    maxArea = max(t, maxArea);
                }
            }
        }
        
        return maxArea;
    }
};