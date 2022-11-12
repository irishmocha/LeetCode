class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> v;
        
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            int lower = max(firstList[i][0], secondList[j][0]);
            int upper = min(firstList[i][1], secondList[j][1]);
            
            if (lower <= upper) {
                v.push_back({lower, upper});
            }
            
            firstList[i][1] < secondList[j][1] ? ++i : ++j;
            
        }
        return v;
    }
};