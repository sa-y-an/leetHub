class Solution {
    vector <int> dp;
public:
    
    int minCost(vector <int> &days, vector <int> &costs,int idx){
        
        if( idx == days.size() )
            return 0;
        
        if( dp[idx] != -1 )
            return dp[idx];
        
        int op1 = costs[0] + minCost(days,costs,idx+1);
        int nextValidDay = days[idx]+ 6, newIdx = days.size();    
        for( int i = idx+1 ; i < days.size() ; i++){
            if( days[i] > nextValidDay ){
                newIdx = i;
                break;
            }
        }
        int op2 = costs[1] + minCost(days,costs,newIdx);
        newIdx = days.size(), nextValidDay = days[idx]+29;
        for( int i = idx+1 ; i < days.size() ; i++){
            if( days[i] > nextValidDay ){
                newIdx = i;
                break;
            }
        }        
        
        int op3 = costs[2] + minCost(days,costs,newIdx);
        return dp[idx] = min({op1,op2,op3});  
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        dp.resize(n,-1);
        return minCost(days,costs,0);
    }
};