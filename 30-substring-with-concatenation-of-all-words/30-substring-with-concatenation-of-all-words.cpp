class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        unordered_map <string,int> mpp;
        for( auto &s : words )
            mpp[s]++;
        
        int n = s.size();
        int l = 0;
        int len = words[0].size();
        int k = words.size();
        
        vector <int> ans;
        
        while( l < n - k*len + 2  ){
            
            unordered_map <string,int> curr;
            int r = l;
            string temp = s.substr(r,len);
            
            int cnt = 0;
            while( mpp.count(temp) and curr[temp] < mpp[temp] ){
                curr[temp]++;
                r += len;
                temp = s.substr(r,len);
                cnt++;
            }
            
            if( cnt == words.size() ){
                ans.push_back(l);
            }
            
            l++;
        }
        
        return ans;
    }
};