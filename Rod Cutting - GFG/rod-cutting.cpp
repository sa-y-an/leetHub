// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

int getPrices(vector <vector <int>> &dp, vector <int> &prices, int idx , int length){

	int n = prices.size();
	if( idx > length  ) return 0;
	if( dp[idx][length] != -1 ) return dp[idx][length];

	int cut = prices[idx-1] + getPrices(dp, prices, idx, length-idx);
	int notCut = getPrices(dp, prices, idx+1, length);

	return dp[idx][length] = max(cut, notCut);

}


class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector <int> prices( price, price + n );
        int length = n;
    	vector <vector <int>> dp(n+1, vector <int> (length+1,-1));
    	return getPrices(dp, prices, 1, length);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends