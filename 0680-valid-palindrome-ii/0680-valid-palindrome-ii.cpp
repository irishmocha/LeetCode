class Solution {
    
public:
    bool isPal(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        int lower = 0, upper = s.length() - 1;
        
        while (lower < upper) {
            if (s[lower] != s[upper]) {
                return isPal(s, lower + 1, upper) || isPal(s, lower, upper - 1);
            }
            lower++;
            upper--;
        }
        
        return true;
    }
};