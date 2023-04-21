class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char,int>> st;
        int n = s.size();
        
        for( int i = 0 ; i < n ; i++){
            if( st.empty() || st.top().first != s[i] ) st.push({s[i],1});
            else if ( st.top().second < k-1) st.push({s[i],st.top().second+1});
            else {
                int x = k-1;
                while(x--) st.pop();
            }
        }
        
        string str;
        while( !st.empty()){
            str += st.top().first;
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};