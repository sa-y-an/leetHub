class Solution {
public:
    int numSplits(string s) {
        unordered_set <char> st, bk;
        int n = s.size();
        vector <int> prefix(n,0), suffix(n,0);
        for( int i = 0 ; i < n ; i++){
            st.insert(s[i]);
            prefix[i] = st.size();
        }
        
        for( int i = n-1 ; i >= 0 ; i--) {
            bk.insert(s[i]);
            suffix[i] = bk.size();
        }
        
        int ans = 0;
        for( int i = 0 ; i < n-1 ; i++){
            if( prefix[i] == suffix[i+1]) ans++;
        }
        return ans;
    }
};