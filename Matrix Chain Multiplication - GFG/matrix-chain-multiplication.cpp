// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
const int INF = 1e9;

class Solution{
    vector<vector<int>> dp;
public:

    int dfs(vector<int> &arr, int l, int r)
    {
    
        if (dp[l][r] != -1)
            return dp[l][r];
    
        if (l == r)
            return dp[l][r] = 0;
    
        int ans = INF;
        for (int k = l; k < r; k++)
        {
            int ops = arr[l - 1] * arr[k] * arr[r];
            int left = dfs(arr, l, k);
            int right = dfs(arr, k + 1, r);
    
            ans = min(ans, ops + right + left);
        }
    
        return dp[l][r] = ans;
    }

    int matrixMultiplication(int N, int arr1[])
    {
        // code here
        vector <int> arr(arr1, arr1+N);
        int n = arr.size();
        dp.resize(n, vector<int>(n, -1));
        return dfs(arr, 1, n - 1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends