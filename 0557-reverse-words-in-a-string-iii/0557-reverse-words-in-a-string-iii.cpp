class Solution {
public:
    string reverseWords(string s) {
        string answer = "";
        
        stringstream ss(s);
        string str;
        while (getline(ss, str, ' ')) {
            reverse(str.begin(), str.end());
            answer += (str + " ");
        }
        string r(answer.begin(), answer.end() - 1);
        return r;
    }
};