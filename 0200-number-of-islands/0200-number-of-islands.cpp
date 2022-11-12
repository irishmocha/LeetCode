class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        int answer = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    q.push({i, j});
                    while (!q.empty()) {
                        auto pos = q.front();
                        // int x = q.front().first;
                        // int y = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; ++i) {
                            int nx = pos.first + dx[i];
                            int ny = pos.second + dy[i];
                            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                                if (grid[nx][ny] == '1') {
                                    q.push({nx, ny});
                                    grid[nx][ny] = '0';
                                }
                            }
                        }
                    }
                    ++answer;
                }
            }
        }
        return answer;
    }
};