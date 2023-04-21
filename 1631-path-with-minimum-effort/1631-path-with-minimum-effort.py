class Solution(object):
    def minimumEffortPath(self, heights):
        m, n = len(heights), len(heights[0])
        DIR = [0, 1, 0, -1, 0]
        
        def dfs(r, c, visited, threadshold):
            if r == m-1 and c == n-1: return True # Reach destination
            visited[r][c] = True
            for i in range(4):
                nr, nc = r+DIR[i], c+DIR[i+1]
                if nr < 0 or nr == m or nc < 0 or nc == n or visited[nr][nc]: continue
                if abs(heights[nr][nc]-heights[r][c]) <= threadshold and dfs(nr, nc, visited, threadshold): return True
            return False
        
        def canReachDestination(threadshold):
            visited = [[False] * n for _ in range(m)]
            return dfs(0, 0, visited, threadshold)
        
        left = 0
        ans = right = 10**6
        while left <= right:
            mid = left + (right-left)/2
            if canReachDestination(mid):
                right = mid - 1 # Try to find better result on the left side
                ans = mid
            else:
                left = mid + 1
        return ans