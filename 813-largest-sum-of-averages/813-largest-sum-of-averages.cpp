class Solution {
    vector <int> prefix;
    vector <vector <vector <double>>> dp;
public:
    double maxAvg(int idx, int start, int k){
        
        int n = prefix.size();
        if( idx == n )
            return -1e6;
        
        if( dp[idx][start][k] != -1 )
            return dp[idx][start][k];
        
        double ans;
        if( k == 0 ){
            int total = prefix[n-1];
            if( start >= 1 )
                total -= prefix[start-1];
            int nums = n-start;
            ans = (total*1.0)/nums;
            return dp[idx][start][k] = ans;
        }
        
        // put
        int total = prefix[idx];
        if( start >= 1)
            total -= prefix[start-1];
        int nums = idx-start+1;
        double put = (total*1.0)/nums + maxAvg(idx+1,idx+1,k-1);
        
        // not put
        double notPut = maxAvg(idx+1,start,k);
        return dp[idx][start][k] = max(put,notPut);
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        prefix.resize(n,0);
        prefix[0] = nums[0];
        for( int i = 1; i < n ; i++)
            prefix[i] = prefix[i-1]+nums[i];
        dp.resize(n+1, vector <vector <double>> (n+1, vector <double> (k+1,-1)));
        return maxAvg(0,0,k-1);
    }
};