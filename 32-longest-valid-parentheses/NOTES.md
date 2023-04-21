## Big Idea
​
- The longest contiguous sequence of opening brackets that have been closed are valid. But, there is a catch, if there is an invalid bracket in between two sequences of valid closed opening brackets the streak is broken
​
## Algorithm
- create an array of score whenever an '(' or invalid char is encountered,
- and push its idx into a stck
- when valid closing bracket - pop and score[top] = 1
- now we have a bitonic array score of 0, 1
- find the longest cont 1 in the bitonic array
- whenever there is an invalid entry push a 0 and inc inv count to 1
​