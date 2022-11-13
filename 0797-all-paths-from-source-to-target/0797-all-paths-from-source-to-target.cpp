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
        vector<int> path;
        q.push({0});
        vector<vector<int>> answer;
        while (!q.empty()) {
            path = q.front();
            q.pop();
            if (path.back() == n - 1) {
                answer.push_back(path);
            }
            for (auto ele : adj[path.back()]) {
                vector <int> temp = path;
                temp.push_back(ele);
                q.push(temp);
            }
        }
        
        return  answer;
    }
};