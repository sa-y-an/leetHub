class Solution {
public:
    
    int minMoves(string &s){
        
        if( s.size() < 2)
            return 0;
            
        if( s[0] == s.back() ){
            string temp = s.substr(1,s.size()-2);
            return minMoves(temp);
        }
        
        int pos = s.find(s.back());
        int n = s.size();
        if( pos == n-1 ){
            int ans = n/2;
            s.pop_back();
            return ans + minMoves(s);
        }
            
        int ans = pos;
        s.pop_back();
        s.erase(s.begin()+pos);
        return ans + minMoves(s);
    }
    
    int minMovesToMakePalindrome(string s) {
        return minMoves(s);
    }
};