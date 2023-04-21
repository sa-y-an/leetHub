class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int k) {
        
        unordered_set <int> prev;
        int ans = 0;
        for( auto num : nums ){
            if( prev.count(num-k) && prev.count(num-2*k) )
                ans++;
            prev.insert(num);
        }
        
        return ans;
    }
};