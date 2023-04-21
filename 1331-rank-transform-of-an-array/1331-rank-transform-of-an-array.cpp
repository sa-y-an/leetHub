class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        set <int> s1(arr.begin(),arr.end());
        vector <int> s(s1.begin(),s1.end());
        vector <int> ans;
        for( int x : arr){
            int idx = lower_bound(s.begin(),s.end(),x)-s.begin();
            ans.push_back(idx+1);
        }
        return ans;          
    }
};