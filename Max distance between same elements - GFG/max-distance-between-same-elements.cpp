// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // your task is to complete this function
    int maxDistance(int arr[], int n){
    //Code here
        unordered_map <int, int > umap;
        int maxDistance = 0;
        for( int i = 0 ; i < n ; i++) {
           if( umap.count(arr[i]) > 0 ) maxDistance = max(maxDistance, i-umap[arr[i]]);
           else umap[arr[i]] = i;
        }
        
        return maxDistance;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxDistance(arr,n)<<endl;
    }
    return 0;
}  // } Driver Code Ends