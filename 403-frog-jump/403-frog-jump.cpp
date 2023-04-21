vector <int> mover = {-1,0,1};
class Solution {
private:
    unordered_map <int, int> indices;
    int end;
    vector<vector <int>> dp;
public:
    bool isPossible(int pos, int jump){
        
        if( pos == end ) return true;
        if( pos < 0 ) return false;
        if( indices.count(pos) == 0 ) return false;
        if( dp[indices[pos]][indices[jump]] != -1) return dp[indices[pos]][indices[jump]];
        
        for( auto move : mover ){
            if( jump + move + pos > pos ){    
                if(isPossible( jump + move +pos , move+jump)) return dp[indices[pos]][indices[jump]] = 1;
                else dp[indices[pos]][indices[jump]] = 0;
            }
        }
        return false;
    }
    
    bool canCross(vector<int>& stones) {
        for( int i = 0 ; i < stones.size() ; i++ ) indices[stones[i]] = i;
        end = stones.back();
        const int N = stones.size();
        dp.resize(N+10, vector <int> (N+10,-1));
        return isPossible(stones[0],0);
    }
};