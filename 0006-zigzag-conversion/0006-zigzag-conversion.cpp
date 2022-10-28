class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        int len = s.length();
        string res = "";
        
        int tmp = 0;
        int circle = numRows - 1, inc = 2 * circle;
        while (tmp < len) {
            res += s[tmp];
            tmp += inc;
        }
        
        for (int i = 1; i < circle; ++i) {
            tmp = i;
            int sum = inc;
            while (tmp < len) {
                res += s[tmp];
                if (sum - tmp < len)
                    res += s[sum - tmp];
                tmp += inc;
                sum += 2 * inc;
            }
        }
        
        tmp = circle;
        while (tmp < len) {
            res += s[tmp];
            tmp += inc;
        }
        
        return res;
    }
};