class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";

        int n = s.size();
        for (int i = 0; i < n; i++) {
            string cur = func(s, i - 1, i + 1);
            if (cur.size() > res.size()) res = cur;
            cur = func(s, i, i + 1);
            if (cur.size() > res.size()) res = cur;
        }
        
        return res;
    }
    
    string func(string s, int left, int right){
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        
        return s.substr(left + 1, right - left - 1);
    }
};