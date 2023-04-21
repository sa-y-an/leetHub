## Big Idea
​
- Generate a bitmask of words ( using alphabets as idx)
- Keep two maps 1 for replace, 1 for deletion
- while traversing the array check if the same mask was seen before then union both
- unset a bit and check if it was seen before ( equivalent to deletion ) both in the deletion map and normal map
- del[map] = unset word
- set a bit and check (equivalent to insertion )