// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
    vector <vector <int> > dp;
public:

    bool subsets(vector <int> & arr, int target , int idx = 0 ){
        
        if( target == 0 ) return true;
        if( idx >= arr.size() or target < 0 ) return false;
        if( dp[idx][target] != -1 ) return dp[idx][target];
        
        if( subsets(arr, target-arr[idx], idx+1 ) or  subsets(arr, target, idx+1)) 
            return dp[idx][target] = 1;
        else 
            return dp[idx][target] = 0;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        dp.resize(arr.size(), vector <int> (sum+1,-1));
        return subsets(arr, sum);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends