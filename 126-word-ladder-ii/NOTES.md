### Ideas
​
- In BFS check visited[node] after dequeing, as a node may be added multiple times before visiting, thus can result in inf loop
- Level[child] = min(level[child], level[par]+1) : as we dont end the bfs, the child maybe updated later
- Rest is trivial (keep a array of parents and backtrack to generate all possible combinations)