## Idea
​
- Sort comparator ```a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]```
- This ensures that all are sorted by x and those that are not are sorted by y in rev
- Now when we try to pick the reqd elt from back
- if we find one with less than maxY we know its the ans as all elts to the right has greater x, and those elt with equal value with greater y are to its left