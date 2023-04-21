// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
const int m = 1e9+7;
class Solution{
    vector <vector <int>> dp;
    int N;
public:

    ll dfs(int idx, int prev){
        
        if( idx == N )
            return 1;
        
        if( dp[idx][prev] != -1 )
            return dp[idx][prev]; 
        
        ll zero = dfs(idx+1,0)%m;
        ll one = 0;
        if( prev == 0 ){
            one = dfs(idx+1,1)%m;
        }
        
        return dp[idx][prev] = (one%m +zero%m)%m;
    }
    
	// #define ll long long
	ll countStrings(int n) {
	    
	    N = n;
	    dp.resize(n,vector <int> (2,-1));
	    return dfs(0,0)%m;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends