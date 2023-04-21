class Solution {
    vector <vector <int>> dp;
public:
    
    int lcs( vector <int> &nums1, vector <int> &nums2, int i1, int i2 ){
        if( i1 < 0 or i2 < 0 ) 
            return 0;
        if( dp[i1][i2] != -1 )
            return dp[i1][i2];
        if( nums1[i1] == nums2[i2] )
            return dp[i1][i2] = 1+ lcs(nums1, nums2, i1-1, i2-1);
        else
            return dp[i1][i2] = max( lcs(nums1, nums2, i1, i2-1), 
                             lcs(nums1, nums2, i1-1, i2) );
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        dp.resize(n, vector <int> (m,-1));
        return lcs(nums1, nums2, n-1, m-1);
    }
};