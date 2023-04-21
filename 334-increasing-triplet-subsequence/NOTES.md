## Explanation
​
- ```[7,8,6,9]``` : when we reach 9, we find it is greater than 7 and 8 thus we return true
- here s = 6, m = 8; but since medium is 8 we can be sure there was a number smaller, than 8 before it, otherwise small would have been 8. This is the essence of the problem, when we update middle we are sure there is a number smaller than middle to its left, else it would be left itself.
​