class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        long long total = accumulate(nums.begin(), nums.end(), 0*1LL);
        for( int i = 0 ; i < n  ; i++){
            int idx = abs(nums[i]) - 1;
            if ( nums[idx] < 0 ){
                dup = idx+1;
                break;
            }
            nums[idx] *= -1;
        }
        
        return {dup, (int) ((n*(n+1))/2-(total-dup))};
    }
};