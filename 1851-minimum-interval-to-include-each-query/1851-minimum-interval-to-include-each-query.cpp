class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] - a[0] < b[1] - b[0];
        });

        set<pair<int, int>> queryset;
        for (auto i = 0; i < queries.size(); ++i) {
            queryset.insert({queries[i], i});
        }

        vector<int> answer(queries.size(), -1);
        for (auto& i : intervals) {
            auto lower = queryset.lower_bound({i[0], 0});
            auto upper = queryset.upper_bound({i[1], queries.size()});
            
            while (lower != upper){
                int ind = lower -> second;
                answer[ind] = i[1] - i[0] + 1;
                queryset.erase(lower++);
            }
        }

        return answer;
    }
};
