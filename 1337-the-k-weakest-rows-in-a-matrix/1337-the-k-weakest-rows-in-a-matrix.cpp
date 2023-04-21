bool comparator( pair <int,int> &a , pair <int, int> &b){
    if( a.first > b.first ) return true;
    if( a.first == b.first and a.second < b.second ) return true;
    return false;
}

class Solution {
public:
    
    
    int numCivilian(vector <int> &people){
        int l = 0 , h = people.size()-1;
        int ans = -1;
        while( l <= h ){
            int mid = l + (h-l)/2;
            if( !people[mid] ){
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        
        if( ans == -1 ) return 0;
        return people.size()-ans;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector <pair<int,int>> civilians;
        for( int i= 0 ; i < mat.size() ; i++)
            civilians.push_back({numCivilian(mat[i]),i});
        
        sort( civilians.begin(), civilians.end(), comparator);
        
        vector <int> ans;
        const int n =mat.size(); 
        for( int i = 0 ; i < k  ; i++) ans.push_back(civilians[i].second);
        
        return ans;
        
    }
};