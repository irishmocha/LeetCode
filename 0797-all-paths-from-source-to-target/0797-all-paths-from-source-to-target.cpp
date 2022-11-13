class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            for (auto g : graph[i]) {
                adj[i].push_back(g);
            }
        }
        
        queue<vector<int>> q;
        q.push({0});
        vector<int> now;
        vector<vector<int>> answer;
        while (!q.empty()) {
            now = q.front();
            q.pop();
            if (now.back() == n - 1) {
                answer.push_back(now);
            }
            for (auto ele : adj[now.back()]) {
                vector<int> temp = now;
                temp.push_back(ele);
                q.push(temp);
            }
        }
        
        return  answer;
    }
};