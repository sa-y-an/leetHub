class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        n = len(products)
        products.sort()  # Sort by increasing lexicographically order of products
        ans = []
        startIdx, endIdx = 0, n - 1
        for i, c in enumerate(searchWord):
            while startIdx <= endIdx and (i >= len(products[startIdx]) or products[startIdx][i] < c):
                startIdx += 1
            while startIdx <= endIdx and (i >= len(products[endIdx]) or products[endIdx][i] > c):
                endIdx -= 1

            if startIdx <= endIdx:
                ans.append(products[startIdx:min(startIdx+3, endIdx+1)])
            else:
                ans.append([])
        return ans