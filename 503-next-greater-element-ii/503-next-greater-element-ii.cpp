class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& array) {
        int n = array.size();
        if( n == 0 )
            return {};
        for( int i = 0 ; i < n ; i++) array.push_back(array[i]);

        n = array.size();
        stack <int> st;
        vector <int> nge(n,0);

        for( int i = n-1 ; i >= 0 ; i--){
            int num = array[i];
            while( !st.empty() && st.top() <= num )
              st.pop();
            if( st.empty() ) 
              nge[i] = -1;
            else 
              nge[i] = st.top();
            st.push(num);
        }

        vector <int> ans(n/2 , 0 );
        for( int i = 0 ; i < n/2 ; i++)
            ans[i] = nge[i];

        return ans;
    }
};