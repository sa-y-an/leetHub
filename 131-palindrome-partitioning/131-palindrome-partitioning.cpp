class Solution {
    vector <vector<string>> ans;
    vector <vector <int>> dp;
public:
    
    bool isPalindrome(string &s, int l,int r){
        
        if( dp[l][r] != -1)
            return dp[l][r];
        int i = l , j = r;
        bool ans = true;
        while( l < r ){
            if( s[l++] != s[r--] ){
                ans = false;
                break;
            }
        }
        return dp[i][j] = ans;
    }
    
    void dfs(string &s, int l, int r,vector <string> &curr){
        
        int n = s.size();
        if( l == n ){
            ans.push_back(curr);
            return;
        }
            
        for( int i = l ; i <= r ; i++){
            if( dp[l][i] == 1 || isPalindrome(s,l,i)){
                string temp = s.substr(l,i-l+1);
                curr.push_back(temp);
                dfs(s,i+1,r,curr);
                curr.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        vector <string> temp;
        dp.resize(n, vector <int> (n,-1));
        dfs(s,0,n-1,temp);
        return ans;
    }
};