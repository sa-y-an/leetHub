// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int distinctIds(int arr[], int n, int m){
        // Complete this function
        unordered_map <int, int> umap;
        for( int i = 0 ; i < n ; i++) umap[arr[i]]++;
        
        vector <int> store;
        for( auto &it: umap) store.push_back(it.second);
        
        sort(store.begin(), store.end());
        int k = store.size();
        int i = 0, cnt =0 ;
        
        while( cnt < m  and i < k  ){
            store[i]--;
            if( store[i] == 0 ) i++;
            cnt++;
        }
        return store.size()-i;
        
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
          cin>>arr[i];
        }
    
    	int m ;
    	cin >> m;
        Solution ob;
    	cout << ob.distinctIds(arr, n, m) << endl;
    }
	return 0;
}  // } Driver Code Ends