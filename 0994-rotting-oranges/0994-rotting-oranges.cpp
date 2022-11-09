class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    ++fresh;
                }
            }
        }
        
        int minute = -1;
        while (!q.empty()) {
            int sz = q.size();
            while(sz--) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int r = p.first + dx[i];
                    int c = p.second + dy[i];
                    if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r, c});
                        --fresh;
                    }
                }
            }
            ++minute;
        }
        
        if (fresh > 0) {
            return -1;
        }
        if (minute == -1) {
            return 0;
        }
        
        return minute;
        
    }
};