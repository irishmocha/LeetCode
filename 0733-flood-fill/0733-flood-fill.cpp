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
    
    /*
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        int startColor = image[sr][sc];
        if (startColor == color) return image;
        int e[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        image[sr][sc] = color;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = r + e[k][0];
                int y = c + e[k][1];
                if (x >= 0 && y >= 0 && x < m && y < n && image[x][y] == startColor) {
                    image[x][y] = color;
                    q.push(make_pair(x, y));
                }
            }
        }
        return image;
    }
    */
    
};