class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.length(), n = abbr.length();
        int i = 0;
        for (int j = 0; j < abbr.length(); j++) {
            char c = abbr[j];
            if (c >= 'a' && c <= 'z') {
                if (i >= word.length() || word[i] != c)
                    return false;
                i++;
            } else {
                if (abbr[j] == '0') return false;
                int k = j + 1;
                while (k < abbr.length() && abbr[k] >= '0' && abbr[k] <= '9') {
                    k++;
                }
                int len = atoi(abbr.substr(j, k - j).c_str());
                i += len;
                j = k - 1;
            }
        }
        return i == word.length();
    }
};