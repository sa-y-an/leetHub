const int INF = 1e9;
bool comparator(vector <int> &a, vector <int> &b){
    return a[0] < b[0];
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};


class Solution {
    unordered_map <pair<int,int>,int, hash_pair> mpp;
public:
    int minAreaRect(vector<vector<int>>& points) {
        int minArea = INF;
        sort(points.begin(),points.end(),comparator);
        
        for( auto & pAbove : points ){
            for( auto & pBelow : points ){
                if( pAbove[0] == pBelow[0] and pAbove[1] > pBelow[1] ){
                    pair<int,int> height = make_pair(pAbove[1],pBelow[1]);
                    if( mpp.count(height) > 0 ){
                        int h = pAbove[1]-pBelow[1];
                        int w = pAbove[0]-mpp[height];
                        minArea = min(h*w, minArea);
                    }
                    mpp[height] = pAbove[0];
                }
            }
        }
        
        return minArea == INF ? 0 : minArea;
    }
};