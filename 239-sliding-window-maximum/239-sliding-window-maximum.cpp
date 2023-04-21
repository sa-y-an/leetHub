class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue <pair<int,int>> pq;
        unordered_set <int> removed;
        int curr = 0;
        vector <int> ans;
        for( int i = 0 ; i < nums.size() ; i++ ){
            pq.push({nums[i],i});
            curr++;
            if( curr == k ){
                
                while( removed.count(pq.top().second) ){
                    int top = pq.top().second;
                    pq.pop();
                    removed.erase(top);
                }

                int top = pq.top().first;
                ans.push_back(top);
                removed.insert(i-k+1);
                curr--;
            }
        }
        return ans;
    }
};