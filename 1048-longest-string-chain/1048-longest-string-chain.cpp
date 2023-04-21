bool comparator(string &a,string &b){
    return a.size() < b.size();
}
class Solution {
public:
    
    bool isStringChain(string &a, string &b){
        int l = 0 , r = 0 ;
        while( r < b.size() and a[l] == b[r]) l++, r++;
        l++;
        while( r < b.size() and a[l] == b[r]) l++, r++;
        return l == a.size() and r == b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(), comparator);
        int n = words.size();
        vector <int> dp(n,0);
        dp[n-1] = 1;
        
        for( int i = n-2 ; i >= 0 ; i--){
            int ans = 0;
            for( int j = n-1 ; j > i ; j--){
                if(isStringChain(words[j],words[i]))
                    ans = max(ans,dp[j]);
            }
            dp[i] = 1 + ans;
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};