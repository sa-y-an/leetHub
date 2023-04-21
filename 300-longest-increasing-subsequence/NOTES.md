### Longest Increasing Subsequence (LIS)
​
- [PDF](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/28461a74f81101874a13d9679a40584d_MIT6_006S20_lec16.pdf)
​
```cpp
// dp (O(n2))
int n = nums.size();
vector <int> dp(n,0);
dp[n-1] = 1;
​
for( int i = n-2 ; i >= 0 ; i--){
int ans = 0;
for( int j = n-1 ; j > i ; j--){
if( nums[j] > nums[i] ){
ans = max(ans, dp[j]);
}
}
dp[i] = 1 + ans;
}
​
return *max_element(dp.begin(), dp.end());
```
​
​
## Solution 2 ( Using Binary Search )
​
### idea
​
- if lower_bound exits : ans[lb] = x
- else ans.pb(x)
- return ans.size();
​
```cpp
vector <int> lis;
for( int x : nums ){
auto it = lower_bound(lis.begin(),lis.end(),x);
if( it == lis.end() ) lis.push_back(x);
else lis[it-lis.begin()] = x;
}
return lis.size();
```
​
​