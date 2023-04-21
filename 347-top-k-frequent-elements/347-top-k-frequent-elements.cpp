class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> umap;
        for( auto num : nums ) umap[num]++;
        priority_queue < pair<int,int> , vector< pair <int,int> > , greater <pair <int,int>> > pq;
        for( auto it: umap){
            pq.push({it.second, it.first});
            if( pq.size() > k ) pq.pop();
        }
        
        vector <int> ans;
        
        while(not pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};