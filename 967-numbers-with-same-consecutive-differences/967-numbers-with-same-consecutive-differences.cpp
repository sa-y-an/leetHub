class Solution {
    vector <int> ans;
public:
    
    void generate(int n, int k, vector <int> &curr){
        
        if( curr.size() == n ){
            int x = 0;
            for( int i = 0 ; i < n ; i++){
                x += curr[i]*pow(10,n-i-1);
            }
            ans.push_back(x);
            return;
        }
        
        int num = curr.back();
        if( num + k < 10 ){
            curr.push_back(num+k);
            generate(n,k,curr);
            curr.pop_back();
        }
        if( k == 0 )
            return;
        if( num - k > -1 ){
            curr.push_back(num-k);
            generate(n,k,curr);
            curr.pop_back();            
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector <int> curr;
        for( int i = 1 ; i < 10 ; i++){
            curr.push_back(i);
            generate(n,k,curr);
            curr.pop_back();
        }
        
        return ans;
    }
};