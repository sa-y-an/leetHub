class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map <char, int> umap;
        for( auto ch: s) umap[ch]++;
        
        priority_queue < pair <int, char> > pq; 
        for( auto &it: umap) pq.push({it.second, it.first});
        
        string ans;
        while( not pq.empty()){
            auto curr = pq.top();
            pq.pop();
            
            if( ans.back() == curr.second ){
                if( pq.empty()) return "";
                auto next = pq.top();
                pq.pop();
                
                ans.push_back(next.second);
                next.first--;
                if( next.first > 0 ) pq.push( { next.first , next.second});
            }
            else {
                curr.first--;
                ans.push_back(curr.second);
            }
            if( curr.first > 0)
                pq.push({curr.first, curr.second});
        }
        
        return ans;
        
    }
};