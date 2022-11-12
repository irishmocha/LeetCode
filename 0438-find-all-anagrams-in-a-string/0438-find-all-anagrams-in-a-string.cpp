class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> up;
        for (char c : p)    ++up[c];

        vector<int> answer;
        unordered_map<char, int> us;
        for (int i = 0; i < s.length(); ++i) {
            ++us[s[i]];
            
            if (i >= (int) p.length()) {
                if (us[s[i - (int) p.length()]] == 1) {
                    us.erase( s[i - (int) p.length()]);
                }
                else {
                    --us[s[i - (int) p.length()]];
                }
            }
            
            if (up == us) {
                answer.push_back(i - p.length() + 1);
            }
        }
        
        return answer;
    }
};