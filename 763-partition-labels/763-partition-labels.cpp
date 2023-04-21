class Solution {
public:
    vector<int> partitionLabels(string &s) {
        vector <int> last(26,0), ans;
        int start = 0 , end = 0, n = s.size();
        for( int i = 0 ; i < n ; i++) last[s[i]-'a'] = i;
        for( int i = 0 ; i < n ; i++){
            end = max(end, last[s[i]-'a']);
            if( i == end ) ans.push_back(end-start+1), start = i+1; 
        }
        return ans;
    }
};