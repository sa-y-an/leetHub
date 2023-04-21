# frequency Stack
​
- Read the question
- It says frequency stack, so it helps to build a stack for every frequqncy
​
- Hash map freq will count the frequence of elements.
* Hash map m is a map of stack.
* If element x has n frequence, we will push x n times in m[1], m[2] .. m[n]
* maxfreq records the maximum frequence.
*
* push(x) will push x tom[++freq[x]]
* pop() will pop from the m[maxfreq]
​
[Source](https://leetcode.com/problems/maximum-frequency-stack/discuss/163410/C%2B%2BJavaPython-O(1)