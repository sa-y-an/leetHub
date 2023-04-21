bool comparator(pair <int,int> &a, pair <int,int> &b){
    if (a.second != b.second )
        return a.second < b.second;    
    return 
        a.first < b.first;
}

class Solution {
    vector <pair<int,int>> info; 
    vector <vector <int>> dp;
public:
    
    int maxValue(int idx, int lt){
        
        int n = info.size();
        if( idx < 0 ) 
            return 0;
        if( dp[idx][lt] != -1 )
            return dp[idx][lt];
        int take = 0 , notTake = 0;
        
        if( lt == n || info[idx].first <= info[lt].first ){
            take = info[idx].first  + maxValue(idx-1,idx);
        }
        notTake = maxValue(idx-1,lt);
        return dp[idx][lt] = max(take, notTake);   
    }
    
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n = scores.size();
        dp.resize(n, vector <int> (n+1,-1));
        for( int i = 0 ; i < n ; i++){
            info.push_back({scores[i],ages[i]});
        }
        
        sort(info.begin(),info.end(),comparator);
        return maxValue(n-1, n);
    }
};