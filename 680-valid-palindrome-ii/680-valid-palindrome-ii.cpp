class Solution {
public:
    bool isValid(string &s , int l , int r){
        while( l < r and s[l] == s[r]) l++, r--;
        return l >= r; 
    }
    
    bool validPalindrome(string &s) {
        int l = 0 , r = s.size()-1;
        while( l < r and s[l] == s[r]) l++, r--;
        if( l >= r ) return true;
        if( isValid(s, l+1 ,r) or isValid(s, l, r-1)) return true;
        return false; 
    }
};