class Solution {
public:
    bool winnerOfGame(string colors) {
        
        // total baal question
        int aCount = 0, bCount = 0;
        int i = 0, n = colors.size();
        
        while( i < n ){
            
            char start = colors[i];
            int cnt= 0;
            while( colors[i] == start ) i++, cnt++;
            
            if( cnt > 2 ){
                if( start == 'A') aCount += cnt-2;
                else bCount += cnt-2;
            }
            
        }
        
        if( aCount > bCount ) return true;
        else return false;
        
    }
};