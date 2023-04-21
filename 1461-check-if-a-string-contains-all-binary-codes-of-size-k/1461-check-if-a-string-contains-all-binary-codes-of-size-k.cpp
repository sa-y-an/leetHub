class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        unordered_set <string> seen;
        deque <char> q;
        int n = s.size();
        
        for( int i = 0 ; i < min(k,n) ; i++) q.push_back(s[i]);
        seen.insert({q.begin(),q.end()});
        
        for( int i = k ; i < n ; i++){
            q.pop_front();
            q.push_back(s[i]);
            seen.insert({q.begin(),q.end()});
        }
        return seen.size() == 1<<k;
    }
};