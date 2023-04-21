class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector <int> ans;
        for( auto &op : ops){
           
            if( op == "+" ){
                int n = ans.size();
                ans.push_back(ans[n-1]+ans[n-2]);
            }
            else if( op == "D"){
                ans.push_back(2*ans.back());
            }
            else if( op == "C"){
                ans.pop_back();
            }
            else{
                int val = stoi(op);
                ans.push_back(val);
            }
        }
        
        return accumulate(ans.begin(), ans.end(), 0);
        
        
    }
};