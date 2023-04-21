class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map <char, int> lastOcc;
        for( int i = 0 ; i < s.size() ; i++) lastOcc[s[i]] = i;
        vector <bool> visited(26,false);
        string ans;
        for( int i = 0 ; i < s.size() ; i++){
            char ch = s[i];
            if( visited[ch-'a'] ) continue;
            if( ans.empty() or ans.back() < ch ) ans.push_back(ch), visited[ch-'a'] = true;
            else {
                while( not ans.empty() and ans.back() >= ch and lastOcc[ans.back()] >= i )
                    visited[ans.back()-'a'] = false, ans.pop_back();
                ans.push_back(ch);
                visited[ch-'a'] =  true;
            }
            
        }
        
        return ans;
    }
};