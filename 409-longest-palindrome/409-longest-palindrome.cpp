class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map <char,int> mpp;
        for( auto ch : s )
            mpp[ch]++;
        
        int ans = 0;
        int rem = 0;
        for( auto &[ch,cnt] : mpp ){
            ans += cnt/2;
            rem += cnt%2;
        }
        
        ans *= 2;
        if( rem > 0 )
            ans++;
        return ans;
    }
};