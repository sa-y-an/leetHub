class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        
        
        sort(passengers.begin(),passengers.end());
        sort(buses.begin(), buses.end());
        
        unordered_set <int> s(passengers.begin(),passengers.end());
        vector <int> cap(buses.size(), capacity);
        
        int l = 0, n = passengers.size();
        int last = -1;
        int lastBus = -1;
        for( int i = 0 ; i < n and l < buses.size() ; i++ ){
            
            auto dep = lower_bound(buses.begin()+l,buses.end(),passengers[i]) - buses.begin();
            if( dep >= buses.size() )
                break;
            
            last = i;
            lastBus = dep;
            cap[dep]--;            
            if( cap[dep] == 0 ){
                l = dep+1;
            }
        }
                
        int ans = -1;
        
        if( last == -1 )
            return buses.back();
        
        lastBus = buses.size()-1;        
        if( cap[lastBus] > 0 ){
            int next = buses[lastBus];
            for( int i = next ; i >= passengers[last]-1 ; i-- ){
                if( s.count(i) == 0 )
                    return i;
            }
        }
        
        for( int i = last ; i >= 0 ; i--){
            if( s.count(passengers[i]-1) == 0 )
                return passengers[i]-1;
        }
        
        return ans;
    }
};