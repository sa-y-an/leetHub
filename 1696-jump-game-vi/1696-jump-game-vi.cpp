const int INF =  1e8+7;
class Solution {
public:

    int maxResult(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue <pair<int,int>> pq;
        pq.push({nums[n-1],n-1});
        int curr = nums[n-1];
        
        for( int i = n-2 ; i >= 0 ; i--){
            while( pq.top().second > i+k )
                pq.pop();
            int maxi = pq.top().first;
            curr = nums[i] + maxi;
            pq.push({curr,i});
        }
        
        return curr;
    }
};