class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> mpp;
        unordered_set <char> ts;
        int n = s.size();
        for( int i = 0 ; i < n ; i++){
            if( mpp.count(s[i]) == 0 and ts.count(t[i]) != 0 )
                return false;
            if( mpp.count(s[i]) != 0 and mpp[s[i]] != t[i] )
                return false;
            mpp[s[i]] = t[i];
            ts.insert(t[i]);
        }
        
        return true;
    }
};