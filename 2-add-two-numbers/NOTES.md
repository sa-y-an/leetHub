## Way to solve LinkedList
​
- A rather neat way is to instantiate a preHead object with a random value
- And to return its next object
​
```cpp
ListNode preHead(-1), *prev = &preHead;
\\ code
return preHead.next;
```