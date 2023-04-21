class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int i = 0 , j = 0;
        int n = firstList.size(), m = secondList.size();
        
        vector <vector <int>> ans;
        while( i < n and j < m ){
            
            int l1 = firstList[i][0] , r1 = firstList[i][1],
                l2 = secondList[j][0], r2 = secondList[j][1];
            
            vector <int> temp;
            if( l2 > l1 and r1 >= l2 ) temp = {l2,min(r1,r2)};
            else if( l1 >= l2 and r2 >= l1 ) temp = {l1, min(r1,r2)};
            
            if( !temp.empty() ) ans.push_back(temp);
            if( r1> r2) j++;
            else i++;

        }
        
        return ans;
    }
};