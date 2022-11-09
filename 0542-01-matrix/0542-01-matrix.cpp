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
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.size() == 0) {
            return mat;
        }
        
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = curr.first + dx[i];
                int ny = curr.second + dy[i];
                
                if (
                    (nx >= 0 && ny >= 0 && nx < m && ny < n) &&
                   dist[nx][ny] > dist[curr.first][curr.second] + 1
                   
                   ) {
                    // if (dist[nx][ny] > dist[curr.first][curr.second] + 1) {
                        dist[nx][ny] = dist[curr.first][curr.second] + 1;
                        q.push({nx, ny});
                    // }
                }
            }
        }
        return dist;
    }
};