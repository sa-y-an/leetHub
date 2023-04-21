class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = newInterval[0] , r = newInterval[1];
        vector <vector <int>> ans;
        int i = 0, n = intervals.size() ;
        // before interval encountered
        while( i < n and  l > intervals[i][1]  )
            ans.push_back(intervals[i++]);
        
        while( i < n and intervals[i][0] <= r )
            l = min(l, intervals[i][0]), 
            r = max(r, intervals[i][1]),
            i++;
        
        ans.push_back({l,r});
        
        while( i < n )
            ans.push_back(intervals[i]), i++;
        
        return ans;
    }
};