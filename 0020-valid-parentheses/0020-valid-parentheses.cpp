class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            }
            else {
                if (stk.empty())    return false;
                if (stk.top() == '(' && s[i] == ')') stk.pop();
                else if (stk.top() == '{' && s[i] == '}') stk.pop();
                else if (stk.top() == '[' && s[i] == ']') stk.pop();
                else stk.push(s[i]);
            }
        }
        
        return stk.empty();
    }
};