class Solution {
    vector <bool> visited;
    int len;
public:
    
    bool formBucket(vector<int>& sticks, int idx, int side, int bucket){
                        
        int n = sticks.size();
        if( idx == n and side != 0 )
            return false;
        
        if( bucket == 0 ){
            return true;
        }
        
        if( side == 0 )
            return formBucket(sticks,0,len,bucket-1);
        
        if( visited[idx] )
            return formBucket(sticks,idx+1,side,bucket);
        
        // take 
        bool ans = false;
        if( side - sticks[idx] >= 0 ){
            visited[idx] = true;
            ans |= formBucket(sticks,idx+1,side-sticks[idx],bucket);
            if( ans )
                return true;
            visited[idx] = false;
        }
        
        // notTake 
        ans |= formBucket(sticks,idx+1,side,bucket);
        
        return ans;
    }
    
    bool makesquare(vector<int>& sticks) {
        
        int total = accumulate(sticks.begin(),sticks.end(),0);
        if( total%4 != 0 )
            return false;
        int n = sticks.size();
        visited.resize(n,false);
        len = total/4;
        
        return formBucket(sticks,0,len,4);
    }
};