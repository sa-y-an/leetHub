class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector <int> ans(n,0), lis;
        
        for( int i = 0 ; i < n ; i++){
            int x = obstacles[i];
            if( lis.empty() || lis.back() <= x ){
                lis.push_back(x);
                ans[i] = lis.size();
            }
            else {
                auto ub = upper_bound(lis.begin(), lis.end(), x);            
                int pos = ub - lis.begin();
                lis[pos] = x;
                ans[i] = pos+1;
            }
        }
        return ans;
    }
};