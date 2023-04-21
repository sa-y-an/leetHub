class Solution {
public:
    
    bool isMatch(vector <int> &window, vector <int> &target){
        
        for( int i = 0 ; i < 58; i++){
            if( window[i] < target[i] )
                return false;
        }
        
        return true;
    }
    
    string minWindow(string s, string t) {
        vector <int> window(58,0), target(58,0);
        
        for( char ch: t ) {
            target[ch-'A']++;
        }
        
        int l = 0 , r = 0, mini = s.size()+1, start = -1, n = s.size() ;
        
        while( r < n ){
            
            while( r < n and !isMatch(window,target) ){
                window[s[r++]-'A']++;
            }
            
            while( l < r and isMatch(window,target)){
                int len = r-l;
                if( len < mini ) mini = len, start = l;
                window[s[l++]-'A']--;
            }
            
        }
        
        if( start == -1 ) return "";
        string ans = s.substr(start, mini);
        
        return ans;
    }
};