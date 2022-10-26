class Solution {
public:
    vector<string> ans;
    int N;
    void setParenthesis(int L,int lCnt, int useable, string s){
        
        if(L == N*2){
            ans.push_back(s);
            return;
        }
        if(useable>0)
            setParenthesis(L+1, lCnt, useable-1, s+')');
        if(lCnt<N)
            setParenthesis(L+1, lCnt+1, useable+1, s+'(');
    }
    
    vector<string> generateParenthesis(int n) {
        N = n;
        
        setParenthesis(0, 0, 0, "");
        
        return ans;
    }
};