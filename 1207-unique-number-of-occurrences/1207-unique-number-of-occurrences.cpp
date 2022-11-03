class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> um;
        for (int i = 0; i < arr.size(); ++i) {
            ++um[arr[i]];
        }
        
        unordered_set<int> us;
        for (auto a : um) {
            us.insert(a.second);
        }
        
        return um.size() == us.size();
    }
};