class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for( int i = 31 ; i >= 0 ; i--){
            if( ((n>>i)&1) ) ans++;
        }
        return ans;
    }
};