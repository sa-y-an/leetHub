class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for( char ch : s ){
            if( ch == letter ) cnt++;
        }
        
        return (cnt*100)/s.size();
    }
};