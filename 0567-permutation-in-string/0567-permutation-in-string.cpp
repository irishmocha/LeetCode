class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if(len1 > len2)
            return false;
           
        vector<int> freq1(26, 0), freq2(26, 0);

        for(int i = 0; i < len1; i++){
            freq1[s1[i]-'a']++; // s1에 있는 알파벳이 쓰인 횟수
            freq2[s2[i]-'a']++; // sliding window - len1만큼 이동하면서 사용된 알파벳 체크
        }
        
        // 두 vector가 같다는 뜻은 각 알파벳이 사용된 횟수가 같다는 뜻
        if(freq1 == freq2)  return true;
        
        for(int i = len1; i < len2; i++){
            freq2[s2[i]-'a']++; // sliding window에 들어갔으므로 사용 횟수 추가
            freq2[s2[i-len1]-'a']--; // sliding window에서 빠져나왔으므로 사용 횟수 -1
            if(freq1 == freq2)  return true;
        }
        
        return false;
    }
};