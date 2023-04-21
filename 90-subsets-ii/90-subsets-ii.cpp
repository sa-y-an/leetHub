class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set <vector <int>> s;
        vector <int> empty;
        s.insert(empty);
        for( auto &num : nums ){
            vector <vector <int>> v(s.begin(),s.end());
            for( int i = 0 ; i < v.size() ; i++){
                vector <int> &temp = v[i];
                temp.push_back(num);
                sort(temp.begin(),temp.end());
                s.insert(temp);
            }
        }
        
        return vector <vector<int>> (s.begin(),s.end());
    }
};