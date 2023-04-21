class Solution {
public:
    int firstUniqChar(string s) {
        
        vector <short> freq(26,0);
        for( auto ch : s )
            freq[ch-'a']++;
        
        for( int i = 0 ; i < s.size() ; i++){
            char ch = s[i];
            if( freq[ch-'a'] == 1 )
                return i;
        }
        
        return -1;
    }
};