class Solution {
public:
    int m;
    int n;
        
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
    
    bool isSafe(int i, int j, int m, int n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    
    bool isBorder(int i, int j, int m, int n){
        return (i == 0 || i == m - 1 || j == 0 || j == n - 1);
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j){
                if (board[i][j] == 'O' && isBorder(i, j, m, n)) {
                    board[i][j] = '.';
                    q.push(make_pair(i,j));
                }
            }
        }
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = temp.first + dir[i].first;
                int ny = temp.second + dir[i].second;
                if (isSafe(nx, ny, m, n) && !isBorder(nx, ny, m, n) && board[nx][ny] == 'O') {
                    board[nx][ny]= '.';
                    q.push({nx, ny});
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j]=='O') {
                    board[i][j] = 'X';
                }
				else if(board[i][j]=='.') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};