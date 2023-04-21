class Solution {
public:
    bool isPowerOfFour(int n) {
        if( n < 1 ) return false;      
        else return log10(n)/log10(4) == floor(log10(n)/log10(4)); 
    }
};