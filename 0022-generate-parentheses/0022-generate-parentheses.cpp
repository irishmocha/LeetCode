class Solution {
private:
    vector<string> ans;
public:
    void makeParenthesis (int open, int close, string str)
    {
        if (open > 0)
            makeParenthesis(open-1, close, str + "(");
        if (close > 0 && open < close)
            makeParenthesis(open, close-1, str + ")");
        else if (close == 0)
            ans.push_back(str);
    }
     
    vector<string> generateParenthesis(int n) {
        makeParenthesis(n-1, n, "(");
        return ans;
    }
};