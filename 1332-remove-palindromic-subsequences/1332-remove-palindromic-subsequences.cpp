class Solution {
public:
    
    int removePalindromeSub(string s) {
        if(equal(s.begin(), s.begin() + s.size()/2, s.rbegin())) return 1;
        return 2;
    }
};