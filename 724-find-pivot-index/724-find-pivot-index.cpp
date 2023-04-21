class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefix(n , nums[0]);
        vector <int> suffix(n, nums[n-1]);
        
        for( int i = 1 ; i < n ; i++)
            prefix[i] = nums[i] + prefix[i-1];
        
        for( int i = n-2 ; i >= 0 ; i--)
            suffix[i] = nums[i] + suffix[i+1];
        
        for( int i = 0 ; i < n ; i++){
            if( prefix[i] == suffix[i]) return i;
        }
        
        return -1;
    }
};