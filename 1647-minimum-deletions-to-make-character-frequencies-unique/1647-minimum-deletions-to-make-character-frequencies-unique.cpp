class Solution {
public:
    int minDeletions(string s) {
        
        vector <int> freq(26,0);
        for( char ch : s )
            freq[ch-'a']++;
        
        sort(freq.begin(),freq.end(), greater <int> ());
        int prev = s.size()+1;
        
        int ans = 0;
        for( int x : freq){
            
            if( x == 0 ) break;
            
            if( prev > x ) prev = x;
            else {
                int diff = x - prev;
                if( prev > 0 ){
                    prev--;
                    ans += diff+1;
                }else {
                    prev = 0;
                    ans += diff;
                }
            }
        }
        
        return ans;
    }
};