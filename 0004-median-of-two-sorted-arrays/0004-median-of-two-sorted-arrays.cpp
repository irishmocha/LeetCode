class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        if (nums1.size() % 2 != 0) {
            return (double) nums1[nums1.size() / 2];
        }
        else {
            double mid = nums1.size() / 2;
            return (double) ( ((double)nums1[mid] + (double)nums1[mid - 1]) / 2) ;
        }
    }
};