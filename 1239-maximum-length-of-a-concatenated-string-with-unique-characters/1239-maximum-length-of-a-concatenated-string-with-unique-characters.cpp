class Solution {
public:
    
    bool isMatch(string &a, string &b){
        
        if( a.size() == 0 || b.size() == 0 )
            return true;
        unordered_set <int> s(a.begin(),a.end());
        for( char ch : b ){
            if( s.count(ch) > 0 )
                return false;
        }
        return true;
    }
    
    int maxLength(vector <string> &arr,string &curr, int idx){
        
        if( idx < 0 )
            return 0;
        string &temp = arr[idx];
        int notTake = maxLength(arr,curr,idx-1);
        int take = 0;
        if( isMatch(curr,temp) ){
            string newcurr = curr + temp;
            take = temp.size() + maxLength(arr,newcurr,idx-1);
        }
        return max(take,notTake);
    }
    
    int maxLength(vector<string>& arr) {
        
        vector <string> unique;
        for( auto &str : arr ){
            set <char> s(str.begin(),str.end());
            if( s.size() == str.size() )
                unique.push_back(str);
        }
        string str = "";
        return maxLength(unique,str,unique.size()-1);
    }
};