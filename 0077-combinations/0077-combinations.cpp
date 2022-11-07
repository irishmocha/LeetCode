class Solution {
public:
    void solve(int s, int& n, int k, vector<vector<int>>& answer, vector<int>& picked) {
        if (k == 0) {
            answer.push_back(picked);
            return;
        }
        
        for (int i = s; i <= n; ++i) {
            picked.push_back(i);
            solve(i + 1, n , k - 1, answer, picked);
            picked.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> picked;
        
        solve(1, n, k, answer, picked);
        return answer;
    }
};