class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set <int> s;
        int prev = 0, n = nums.size(), rSum = 0;
        for( int i = 0 ; i < n ; i++){
            rSum += nums[i];
            int mod = rSum%k;
            if( s.count(mod) > 0 )
                return true;
            s.insert(prev);
            prev = mod;
        }
        return false;
    }
};