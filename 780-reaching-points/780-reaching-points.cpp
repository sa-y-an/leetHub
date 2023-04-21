class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while( tx > sx and ty > sy ){
            if( tx < ty ) ty %= tx;
            else tx %= ty;
        }
        
        return ( sx == tx and sy <= ty and (ty-sy)%sx == 0 ) ||
               ( sy == ty and sx <= tx and (tx-sx)%sy == 0);
    }
};