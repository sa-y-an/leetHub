class Solution {
public:
    bool checkString(string s) {
        
        if( s.find('b') == string::npos )
            return true;
        
        int idx = s.find('b');
        for( int i = idx+1 ; i < s.size() ; i++){
            if( s[i] == 'a' )
                return false;
        }
        return true; 
    }
};