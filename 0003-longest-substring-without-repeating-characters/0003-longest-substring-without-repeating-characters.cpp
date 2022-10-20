class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;

        for (int i = 0; i < s.length(); i++) {
            vector<bool> visited(256);  
            for (int j = i; j < s.length(); ++j) {
                if (visited[s[j]]) {
                    break;
                }
                else {
                    answer = max(answer, j - i + 1);
                    visited[s[j]] = true;
                }
            }
            visited[s[i]] = false;
        }
        
        return answer;
    }
};