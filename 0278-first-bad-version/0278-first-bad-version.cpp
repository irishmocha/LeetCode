// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lower = 1;
        int upper = n;
        
        int version;
        while (lower <= upper) {
            version = lower + ((upper - lower) / 2);
            if (isBadVersion(version)) {
                upper = version - 1;
            }
            else {
                lower = version + 1;
            }
        }
        
        return lower;
    }
};