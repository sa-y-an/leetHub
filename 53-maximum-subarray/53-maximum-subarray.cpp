const int INF = 1e9;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans = -1*INF;
        int currSum = -1*INF;
        
        for( auto num : nums ){
            currSum += num;
            currSum = max(currSum, num);
            ans = max(currSum,ans);
            if( currSum < 0 ) currSum = 0;
        }
        
        return ans;
        
    }
};