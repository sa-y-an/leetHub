class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m-1 , r = n-1 , idx = nums1.size()-1;
        while( idx >= 0 ){
            if( l >= 0 and (r < 0 or nums1[l] > nums2[r])) nums1[idx--] = nums1[l--];
            else nums1[idx--] = nums2[r--];
        }
    }
};