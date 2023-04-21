/*
- same as intervals only take care of the case, where an interval is embedded in another
*/

bool comparator( vector <int> & a,vector <int> & b ){
    if( a[0] < b[0] ) return true;
    else if( a[0] > b[0]) return false;
    else{
        if( a[1] < b[1]) return true;
        else return false;
    }
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort( intervals.begin(), intervals.end() , comparator );
        // for( auto &interval : intervals) cout<<interval[0]<<" "<<interval[1]<<"\n";
        int cnt = 0;
        

        int start = intervals[0][0], end = intervals[0][1];
        for( int i = 1 ; i < intervals.size() ; i++){
            if( end > intervals[i][0] ) {
                cnt++;
                if( intervals[i][1] < end ) {
                    end = intervals[i][1];
                    start = intervals[i][0];
                }
            }
            else {
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        return cnt;
        
    }
};