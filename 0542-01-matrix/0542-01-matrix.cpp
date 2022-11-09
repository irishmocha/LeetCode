class Solution {
public:
    int m, n;
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isIn(int nx, int ny) {
        if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
            return true;
        }
        return false;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.size() == 0) {
            return mat;
        }
        m = mat.size();
        n = mat[0].size();
        
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
            auto curr = q.front();  q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = curr.first + dx[i];
                int ny = curr.second + dy[i];
                if (isIn(nx, ny) && dist[nx][ny] > dist[curr.first][curr.second] + 1) {
                    dist[nx][ny] = dist[curr.first][curr.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    }
};