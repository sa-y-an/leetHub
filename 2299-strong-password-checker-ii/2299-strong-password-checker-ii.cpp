class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool isLower = false, isUpper = false, isDigit = false, isSpecial = false;
        char prev;
        string sp = "!@#$%^&*()-+";
        set <char> s(sp.begin(),sp.end());
        int n = password.size();
        for( int i = 0 ; i < n ; i++){
            
            if( i != 0 and password[i] == prev)
                return false;
            char ch = password[i];
            if( islower(ch)) isLower = true;
            if( isupper(ch)) isUpper = true;
            if( isdigit(ch)) isDigit = true;
            if( s.count(ch) ) isSpecial = true;
            
            prev = password[i];
        }
        
        return isLower and isUpper and isDigit and isSpecial and password.size() >= 8;
    }
};