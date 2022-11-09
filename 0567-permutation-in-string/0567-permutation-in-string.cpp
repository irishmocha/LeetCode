class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            ++freq1[s1[i] - 'a'];
            ++freq2[s2[i] - 'a'];
        }
        
        if (freq1 == freq2) {
            return true;
        }
        
        for (int i = s1.size(); i < s2.size(); ++i) {
            cout << freq2[s2[i] - 'a'] << endl;
            ++freq2[s2[i] - 'a']; // sliding window에 들어갔으므로 사용 횟수 추가
            cout << freq2[s2[i - s1.size()] - 'a'] << endl;
            --freq2[s2[i - s1.size()] - 'a']; // sliding window에서 빠져나왔으므로 사용 횟수 -1
            if (freq1 == freq2) {
                return true;
            }
        }
        
        return false;
    }
};