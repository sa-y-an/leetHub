vector <string> keyPad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
    string chosen;
    vector <string> ans;
public:
    
    void combine(string &digits, int idx = 0){
        if( idx == digits.size()) ans.push_back(chosen);
        else {
            int digit = digits[idx]-'0';
            for( auto letter : keyPad[digit]){
                chosen[idx] = letter;
                combine(digits,idx+1);
            }
        }
    }
    
    vector<string> letterCombinations(string &digits) {
        if( digits.size() == 0 ) return {};
        chosen.resize(digits.size());
        combine(digits);
        return ans;
    }
};