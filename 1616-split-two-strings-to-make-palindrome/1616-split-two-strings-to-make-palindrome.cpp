class Solution {
public:
    
    bool isPalindrome(string &str){
        int i = str.size()-1, j = 0;
        while( j < i and str[j] == str[i]) i--, j++;
        return j >= i;
    }
    
    
    bool check(string &a, string &b){
        if( isPalindrome(a) or isPalindrome(b) ) return true;
        
        int n = a.size() , l = 0 , r = n-1;
        
        while( l < r and a[l] == b[r] ) l++ , r--;
        if( l >= r ) return true;
        
        string left = a.substr(l, r-l+1);
        if( isPalindrome(left)) return true;
        
        string right = b.substr(l, r-l+1); 
        if( isPalindrome(right)) return true;
        
        return false;
    }
    
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b) or check(b,a);
    }
};