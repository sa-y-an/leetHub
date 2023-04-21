class Solution {
    unordered_set <string> dict;
    vector <vector <int>> dp;
public:
    
    bool isMatch(string &s, int l, int r){
        
        if( l > r )
            return false;
        
        if( dp[l][r] != -1 )
            return dp[l][r];
        
        int n = s.size();
        bool ans = false;
        
        string left;
        
        for(int i = l ; i <= r ; i++){
            left.push_back(s[i]);
            if( dict.count(left) ){
                ans |= isMatch(s,i+1,r);
            }
        }
        
        ans |= dict.count(left);
        return dp[l][r] = ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for( auto &word : wordDict){
            dict.insert(word);
        }
        int n = s.size();
        dp.resize(n, vector <int> (n,-1));
        return isMatch(s,0,n-1);
    }
};