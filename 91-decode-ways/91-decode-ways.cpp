class Solution {
public:
    int numDecodings(string str) {
        
        vector <int> ways(str.size(), 0);
        int n = str.size();
        
        if( '1' <= str[n-1] and str[n-1] <= '9' ){
            ways[n-1] = 1;
        }
        
        if( str.size() < 2 ) return ways[0];
        
        
        if ( '1' <= str[n-2] and str[n-2] <= '9' ){
            ways[n-2] = ways[n-1];
            int i = n-2;
            if( str[i] == '1' ){
                if( str[i+1] >= '0' and str[i+1] <= '9' ){
                    ways[i] += 1;
                }
            }
            if( str[i] == '2' ){
                if( str[i+1] >= '0' and str[i+1] <= '6' ){
                    ways[i] += 1;
                }
            }
            
            
        }
        
        
        for( int i = n-3 ; i >=0 ; i--){
            
            
            if( ways[i+1] == 0 and ways[i+2] == 0  ) break;
            
            if( str[i] >= '1' and str[i] <= '9' ){
                ways[i] = ways[i+1];
                    
                
                if( str[i] == '1' ){
                    if( str[i+1] >= '0' and str[i+1] <= '9' ){
                        ways[i] += ways[i+2];
                    }
                }
                if( str[i] == '2' ){
                    if( str[i+1] >= '0' and str[i+1] <= '6' ){
                        ways[i] += ways[i+2];
                    }
                }
                
                
            }
            
        }
        
        
        
        return ways[0];
        
    }
};