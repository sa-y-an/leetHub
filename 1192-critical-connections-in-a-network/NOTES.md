## Idea
​
- To find bridges, we need to check for backedges
- if a node has a backedge it is not a bridge, as it can be reached twice
- to check for backedges to keep track of the time by running dfs when we enter a node
- while dfs if we find a visited != parent, then it is a backedge
- and we update the low of the edge to the low of the visited node
- while backtracking we update the low of the parent,
- **now to check for bridge**
- we check if the low of a child > discovery time of the node
- if true its a bridge, as otherwise as otherwise its low would have been updated via a backedge
​
## Code
​
```cpp
void dfs(int ver, int par = -1 , int timer = 0){
​
// visit a vertex and set its low and discovery times
visited[ver] = true;
disc[ver] = timer;
low[ver] = timer;
​
//
for( int child : adjList[ver]){
// if the child is a parent continue
if( visited[child] and child == par )
continue;
​
// else if child is not a parent but was visited before,
// this means this is a backedge
// hence we update its low to the discovery of the ver
if( visited[child] )
low[ver] = min(low[child], low[ver]);
​
// if not visited do a dfs on the child
else
dfs(child, ver, timer+1);
​
// backtracking steps
​
// we update the low of the ver to the low of its child
// since any of its low might get updated due to a backedge
low[ver] = min(low[child], low[ver]);
​
// if the low of the child > discovery time of the vertex
// it implies it has no backedge and it can only be reached
// via its parent
​
if( low[child] > disc[ver] ){
ans.push_back({ver,child});
}
}
}
```
​
​