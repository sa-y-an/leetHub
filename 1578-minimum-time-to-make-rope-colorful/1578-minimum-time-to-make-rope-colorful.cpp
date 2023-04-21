static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int i = 0 , n = colors.size();        
        int ans = 0;
        
        while( i < n-1 ){
        
            int _sum = 0 , _max = INT_MIN ;
            while( i < n-1 and colors[i] == colors[i+1] ) {
                _sum += neededTime[i];
                _max = max(neededTime[i], _max);               
                i++;
            }
            if( _sum > 0 ){
                _sum += neededTime[i];
                _max = max(neededTime[i], _max);
                ans += _sum - _max;
            }
            
            i++;
            
        }
        
        
        return ans;
    }
};