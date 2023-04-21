class Solution {
public:
    bool squareIsWhite(string s) {
        int y = s[1]-'0';
        int x = s[0]-'a';
        if( y%2 != 0 )
            return x%2 != 0;
        else
            return x%2 == 0;
    }
};