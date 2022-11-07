class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.size() == 0) {
            return mat;
        }
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = curr.first + dir[i][0];
                int ny = curr.second + dir[i][1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (dist[nx][ny] > dist[curr.first][curr.second] + 1) {
                        dist[nx][ny] = dist[curr.first][curr.second] + 1;
                        q.push({ nx, ny });
                    }
                }
            }
        }
        return dist;
    }
};