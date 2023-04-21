### My Approach
- 2 subproblems
- search space consists of a monotonic function
- f(x) : possible to form subarrays of size m with sum <= x
- We greedily check if given the condition we can form grps <= m ( as if we can form with lesser grps obviously we can leave some out to form even smaller but more grps and thus further reducing the sum)
- Once we have our monotonic function ready it is a typical binary search
​
### Top Voted Leetcode:
​
##### We can break this problem into two smaller problems:
​
- Given an array (A), number of cuts (CUTS), and the Largest sum of sub-arrays (MAX). Can you use at most CUTS cuts to segment array A into CUTS + 1 sub-arrays, such that the sum of each sub-array is smaller or equal to MAX?
- Given a lower bound (left), an upper bound (right), an unknown bool array (B), and an API uses i as input and tells you whether B[i] is true. If we know there exists an index k, that B[i] is false when i < k, and B[i] is true when i >= k. What is the fastest way to find this k (the lower bound)?
#### Solution to the first sub-problem (Skip this part if you already knew how to solve 1st sub-problem):
For the first question, we can follow these steps:
​
For each element in the array, if its value is larger than MAX, we know it's not possible to cut this array into groups that the sum of all groups are smaller than MAX. (Reason is straightforward, if A is [10, 2, 3, 5] and MAX is 6, even you have 3 cuts by which you can cut A as [[10], [2], [3], [5]], the group containing 10 will still be larger than 6).
Use greedy algorithm to cut A. Use an accumulator ACC to store the sum of the currently
processed group, and process elements in A one by one. For each element num, if we add num with ACC and the new sum is still no larger than MAX, we update ACC to ACC + num, which means we can merge num into the current group. If not, we must use a cut before num to segment this array, then num will be the first element in the new group.
If we didn't go through A but already used up all cuts, then it's not possible only using CUTS cuts to segment this array into groups to make sure sum of each sub-array is smaller than MAX. Otherwise, if we can reach the end of A with cuts left (or use exactly CUTS cuts). It's possible to do so.
Then the first question is solved.
​