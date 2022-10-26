class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        int lower = 0;
        int upper = height.size() - 1;
        while (lower < upper) {
            int t = height[upper] > height[lower] ? height[lower] : height[upper];
            int g = (upper - lower) * t;
            
            height[upper] > height[lower] ? ++lower : --upper;
            answer = max(g, answer);
        }
        return answer;
    }
};