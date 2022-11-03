class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            int j;
            for (j = 0; j < strs[i].size(); j++) {
                if (answer[j] != strs[i][j])
                    break;
            }
            answer = answer.substr(0, j);
            if (answer == "")
                return answer;
        }
        
        return answer;
    }
};