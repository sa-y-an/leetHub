## Idea
​
Dp Recurrence
```
if( matrix[i][j] )
dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
```
​
See striver dp series last video
​