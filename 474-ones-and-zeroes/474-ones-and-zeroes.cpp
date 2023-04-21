int dp[601][101][101];
class Solution {
    vector <pair<int,int>> counts;
public:
    
    void generateCount(vector<string>& strs){
        int n = strs.size();
        counts.resize(n);
        for( int i = 0 ; i < n ; i++){
            unordered_map <int, int> umap;
            for( auto ch : strs[i]) umap[ch]++;
            counts[i] = make_pair(umap['0'],umap['1']);
        }
    }
    
    
    int maxSubset(int idx , int c0, int c1){
        
        if( idx < 0 || (c1 <= 0 and c0 <= 0)) return 0;
        if( dp[idx][c0][c1] != -1 ) return dp[idx][c0][c1];
        auto &[zeros, ones] = counts[idx];
        int take = 0;
        if( c1 > 0 and c0 > 0 and c0 >= zeros and c1 >= ones )
            take = 1+maxSubset(idx-1, c0-zeros, c1-ones);
        else if( c1 >= ones and zeros == 0 )
            take = 1+maxSubset(idx-1, c0-zeros, c1-ones);
        else if( c0 >= zeros and ones == 0 )
            take = 1+maxSubset(idx-1, c0-zeros, c1-ones);
        return dp[idx][c0][c1] = max(take,maxSubset(idx-1, c0, c1));
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        generateCount(strs);
        memset(dp, -1, sizeof(dp));
        return maxSubset(strs.size()-1, m, n);
        
    }
};