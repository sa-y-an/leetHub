class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char, int> umap;
        for( char ch : s) umap[ch]++;
        priority_queue < pair<int,char> > pq;
        for( auto &p : umap ) pq.push({p.second,p.first});
        string str;
        while( !pq.empty()){
            auto top = pq.top();
            pq.pop();
            while( top.first--) str.push_back(top.second);
        }
        return str;
    }
};