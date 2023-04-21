const int INF = 1e9;
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int minRot = INF;
        const int n = tops.size();
        for( int num = 1 ; num < 7 ; num++){
            int cnt = 0 ;
            for(int i = 0 ; i < n ; i++){
                if( tops[i] == num ) continue;
                else if( bottoms[i] == num) cnt++;
                else {
                    cnt = INF ;
                    break;
                } 
            }
            minRot = min(cnt,minRot);
        }

        for( int num = 1 ; num < 7 ; num++){
            int cnt = 0 ;
            for(int i = 0 ; i < n ; i++){
                if( bottoms[i] == num ) continue;
                else if( tops[i] == num) cnt++;
                else {
                    cnt = INF ;
                    break;
                } 
            }
            minRot = min(cnt,minRot);
        }
        
        if( minRot == INF) return -1;
        return minRot;
    }
};

static const auto speedup = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
