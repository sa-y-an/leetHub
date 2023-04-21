class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set <int> prev;
        int n = nums.size();
        for( int i = 1 ; i < n ; i++){
            int curr = nums[i] + nums[i-1];
            if( prev.count(curr) )
                return true;
            prev.insert(curr);
        }
        
        return false;
    }
};