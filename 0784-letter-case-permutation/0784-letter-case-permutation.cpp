class Solution {
public:
    void backtrack(string& s, int i, vector<string>& answer) {
        if (i == s.size()) {
            answer.push_back(s);
            return;
        }
        
        char c = s[i];  // save initial value
        
        // path1: toggle lower/upper case
        s[i] = islower(c) ? toupper(c) : tolower(c);
        backtrack(s, i + 1, answer);
        
        // path2: reset back(NOT go to this path if c is digit)
        if (isalpha(c)) {
            s[i] = c;
            backtrack(s, i + 1, answer);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> answer;
        backtrack(s, 0, answer);
        return answer;
    }
    
};