class Solution {
public:
    bool checkRecord(string s) {
        
        int cnt = 0;
        int i = 0 , n = s.size();
        while( i < n ){
            
            if( s[i] == 'P'){
                i++;
                continue;
            }
            
            int late = 0;
            while( s[i] == 'L'){
                late++; i++;
            }
            
            if( late >= 3 )
                return false;
            
            if( s[i] == 'A')
                cnt++;
            i++;
            
        }
        
        return cnt < 2;
    }
};