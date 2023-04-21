class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map <int,int> modLen;
        int ans = 0;
        for( int x: time){
            int mod = x%60;
            int target = 60-mod;
            if( target == 60 )
                target = 0;
            if( modLen.count(target) > 0 )
                ans += modLen[target];
            modLen[mod]++;
        }
        return ans;
    }
};