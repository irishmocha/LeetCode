class Solution {

public:
    int m;
    int n;
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isIn(int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& image, int x, int y, int color, int org, vector<vector<bool>>& visited) {
        if (visited[x][y]) {
            return;
        }
        
        visited[x][y] = true;
        image[x][y] = color;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isIn(nx, ny) && image[nx][ny] == org) {
                dfs(image, nx, ny, color, org, visited);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        
        m = image.size();
        n = image[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        dfs(image, sr, sc, color, image[sr][sc], visited);
        
        
        return image;
    }
};