typedef pair <int,int> pi;
bool comparator(const vector <int> &a, const vector <int> &b){
    return a[1] < b[1];
}

class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int idx = 0;
        const int n = trips.size();
        priority_queue <pi, vector <pi>, greater <pi>> pq;
        sort(trips.begin(),trips.end(), comparator);
        
        int limit = trips[idx][2];
        int curr = trips[idx][0];
        if( curr > capacity )
            return false;
        pq.push({trips[idx][2],trips[idx][0]});
        idx++;
        if( idx < n and trips[idx][1] >= limit ){
            curr = 0;
            pq.pop();
        }
        while( idx < n and curr + trips[idx][0] <= capacity ){
            curr += trips[idx][0];
            pq.push({trips[idx][2],trips[idx][0]});
            limit = max(limit, trips[idx][2]);
            idx++;
            if( idx < n ){
                int nextStop = trips[idx][1];
                while( !pq.empty() and pq.top().first <= nextStop){
                    curr -= pq.top().second;
                    pq.pop();
                }
            }
        }
            
        return idx >= n;
    }
};