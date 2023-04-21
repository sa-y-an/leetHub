## Logic 
- Since a person has only one of two choices
- Either go to city A or to B 
- We sort the costs array by the difference in cost of sending a person to a - cost of sending her/him to b
- Clearly it will be profitable to send some one to a if the above difference is negative, because then cost of sending him to a is lower 
- The most profit we make by sending a person to a is the one having the most negative difference
- Similiarly for b most profit = highest positive difference
- Thus by sorting them in difference of their costs will give us the required results 
- The first n ( of 2n)  goes to A the rest to b 

### Here is the code for the same 

```cpp
/*
sort by difference in costs of a and b 
send the first n to a, rest to b 
*/

bool comparator ( vector <int> &a, vector <int> &b ){
    if( a[0] - a[1]  < b[0] - b[1]) return true; // sort by difference in cost
    else return false;
}

class Solution {
public:   
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comparator);
        int n = costs.size()/2, ans = 0;
        for( int i = 0 ; i < n ; i++ ) ans += costs[i][0] + costs[i+n][1]; // send the first to a , rest to b
        return ans;
    }
};
```
