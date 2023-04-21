class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int n = nums.size(), m = pow(2,n);
        vector <int> dp;
        dp.push_back(0);
        int maxi = accumulate(nums.begin(),nums.end(),0, 
                             [](int a,int b) {return a|b;});
        int ans = 0;
        for( int x : nums ){
            int sz = dp.size();
            for( int i = 0 ; i < sz ; i++){
                int val = (dp[i]|x);
                dp.push_back(val);
                if( val == maxi )
                    ans++;
            }
        }
        return ans;
    }
};