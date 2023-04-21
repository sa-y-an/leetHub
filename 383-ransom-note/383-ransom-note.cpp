class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector <int> ran(26,0), mag(26,0);
        for( auto ch : ransomNote ) ran[ch-'a']++;
        for( auto ch : magazine ) mag[ch-'a']++;
        
        for( int i = 0 ; i < 26 ; i++){
            if( mag[i] - ran[i] < 0 ) return false;
        }
        
        return true;
    }
    
};