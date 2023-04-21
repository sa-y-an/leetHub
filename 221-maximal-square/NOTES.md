- Same Idea as [LC 1277 (count rects) ](https://leetcode.com/problems/count-square-submatrices-with-all-ones/)
​
```cpp
dp[i][j] = min(dp[i-1][j], dp[i][j-1],dp[i-1][j-1]) + 1
```
​
Watch Erricto or Striver for explanation