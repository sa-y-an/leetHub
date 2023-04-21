const int INF = 1e6;
class Solution {
    vector <vector<int>> dp;
public:
    
    int dfs(vector<int>& nums1, vector<int>& nums2, int idx, int sw ){
        
        int n = nums1.size();
        if( idx >= n )
            return 0;
        if( dp[idx][sw] != -1 )
            return dp[idx][sw];
        
        int s = INF , ns = INF;
        
        if( idx == 0 || (nums1[idx] > nums1[idx-1] and nums2[idx] > nums2[idx-1] ) )
            ns = dfs(nums1,nums2,idx+1,0);
        if( idx == 0 || (nums1[idx] > nums2[idx-1] and nums2[idx] > nums1[idx-1]) ){
            swap(nums1[idx],nums2[idx]);
            s = 1 + dfs(nums1, nums2, idx+1,1);
            swap(nums1[idx],nums2[idx]);
        }
        
        return dp[idx][sw] = min(s,ns);
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        dp.resize(n , vector <int> (2,-1));
        return dfs(nums1,nums2,0,0);
    }
};