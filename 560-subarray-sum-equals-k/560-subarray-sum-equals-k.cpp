class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map <int, int> seen;
        seen[0] = 1;
        for( int x : nums ){
            
            sum += x;
            int target = sum-k;
            if( seen.count(target) > 0 ){
                ans += seen[target];
            }
            seen[sum]++;
        }
        return ans;
    }
};