class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        ::reverse(s.begin(), s.end());
        
        long result = stol(s);
        if(result<= -2147483648 || result >=  2147483647)
            return 0;
        
        return x > 0 ? stoi(s) : stoi(s) * -1;
    }
};