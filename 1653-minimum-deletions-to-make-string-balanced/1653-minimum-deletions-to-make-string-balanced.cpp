const int INF = 1e8+7;

class Solution {
    vector <vector<int>> dp;
public:
    
    int minDel( string &s, int idx, int pivot){
        
        int n = s.size();
        if( idx == n )
            return 0;
        
        if( dp[idx][pivot]  != -1 )
            return dp[idx][pivot];
        
        int ans = INF;
        if( pivot == 0 ){      
            if( s[idx] == 'a'){
                ans = min(ans, minDel(s,idx+1,0));
                ans = min(ans, minDel(s,idx+1,1));
            }else{
                ans = 1 + minDel(s,idx+1,1);
                ans = 1 + minDel(s,idx+1,0);
            }
        }else{
            if( s[idx] == 'a' )
                ans = 1 + minDel(s,idx+1,1);
            else
                ans = minDel(s,idx+1,1);
        }
        
        return dp[idx][pivot] = ans;
        
    }
    
    int minimumDeletions(string s) {

        int n = s.size();
        dp.resize(n,vector <int> (2,-1));
        return min(minDel(s,0,1),minDel(s,0,0));
    }
};