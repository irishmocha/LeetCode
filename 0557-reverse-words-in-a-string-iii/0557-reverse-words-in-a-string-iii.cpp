class Solution {
public:
    string reverseWords(string s) {
        int end = -1;
        
        for (int i = 0; i <= s.length(); ++i) {
            if (i == s.length() || s[i] == ' ') {
                int lower = end + 1;
                int upper = i - 1;
                while (lower < upper) {
                    char t = s[lower];
                    s[lower++] = s[upper];
                    s[upper--] = t;
                }
                end = i;
            }
        }
        
        return s;
    }
};