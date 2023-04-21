class Solution {
public:

    bool isNumber(string& str){
        for (char &c : str) {
            if (c-'0' < 0 or c-'0' > 9) 
                return false;
        }
        return true;
    }
  
    string discountPrices(string s, int d) {
        vector <int> prices;
        vector <long long> dis;
        long k = (100.00-d);
        int i = 0 , n = s.size();
        
        while( i < n ){
            
            string word;
            while( i < n and s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }
            
            
            if( word.size() > 1 and word[0] == '$' and
               word[1] != '-' and word[1]-'0' >= 0 and word[1]-'0' <= 9 ){
                string temp;
                temp = word.substr(1,word.size()-1);
                
                if( isNumber(temp)){
                    long long price = stoll(temp);
                    long long priced = (price*k);
                    dis.push_back(priced);
                }
            }
            i++;
        }
        
        i = 0;
        int idx = 0;
        
        string ans;
        while( i < n ){
            
            string word;
            while( i < n and s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }
            
            if( word.size() > 1 and word[0] == '$' and word[1] != '-' 
               and word[1]-'0' >= 0 and word[1]-'0' <= 9 ){
                string temp = word.substr(1,word.size()-1);
                if( isNumber(temp)){
                    ans += "$";
                    auto dig = to_string(dis[idx]);
                    int sz = dig.size();
                    
                    if( sz == 2 ){
                        ans.push_back('0');
                        ans += '.';
                        for( int j = 0 ; j < sz ; j++){
                            ans.push_back(dig[j]);
                        }
                    }
                    else if( sz == 1 ){
                        ans.push_back('0');
                        ans.push_back('.');
                        ans.push_back('0');
                        ans += dig;
                    }
                    else {
                        int j = 0;
                        for( j = 0 ; j < sz-2 ; j++){
                            ans.push_back(dig[j]);
                        }
                        ans += '.';
                        for( j ; j < sz ; j++){
                            ans.push_back(dig[j]);
                        }
                        if( sz == 1 ) ans.push_back('0');
                    }
                    idx++;
                }
                else {
                    ans += word;
                }
            }
            else {
                ans += word;
            }
            
            if( i < n-1) ans += " ";
            i++;
            
        }
        
        return ans;
    }
};