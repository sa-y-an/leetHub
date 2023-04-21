class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset <int> s(changed.begin(),changed.end());
        vector <int> ans;
        
        while( !s.empty()){
            
            auto top = (--s.end());
            if( *top%2 != 0 ) return {};
            int h = *top/2;
            s.erase(top);
            auto val = s.find(h);
            if( val == s.end()) return {};
            ans.push_back(*val);
            s.erase(val);
            
        }
        
        return ans;
    }
};