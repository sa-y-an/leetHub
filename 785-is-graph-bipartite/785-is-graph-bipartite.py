class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        length = len(graph)
        parent = [i for i in range(length)]

        def find(x):
            if x!=parent[x]:
                parent[x]=find(parent[x])#rank compression
            return parent[x]

        def union(x,y):
            px,py=find(x),find(y)
            if px!=py:
                parent[px]=py

        for i in range(length):
            pari=find(i)
            for j in graph[i]:
                if find(j)==pari:
                    return False
                union(graph[i][0],j)

        return True

        