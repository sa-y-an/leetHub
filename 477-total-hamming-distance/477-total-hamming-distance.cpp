class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ones[32];
        memset(ones, 0, sizeof(ones));
        for( int num : nums ){
            for( int i = 31 ; i >= 0 ; i--){
                ones[i] += ((num>>i)&1);
            }
        }
        
        int ans = 0, n = nums.size();
        for( int i = 0 ; i < 32 ; i++){
            ans += ones[i]*(n-ones[i]);
        }
        return ans;
    }
};