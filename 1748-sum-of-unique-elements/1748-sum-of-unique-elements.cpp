class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map <int,int> mpp;
        for( int x: nums )
            mpp[x]++;
        
        int ans = 0;
        for( auto &[i,j] : mpp){
            if( j == 1 )
                ans += i;
        }
        
        return ans;
    }
};