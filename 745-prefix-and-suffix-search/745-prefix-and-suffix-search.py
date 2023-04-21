class WordFilter:

    def __init__(self, words: List[str]):
        
        self.trie = {}
        for idx, word in enumerate(words):
            pref_suff = word + '#' + word
            for start in range(len(word)):
                curr = self.trie
				# insert pref_suff[start:] to trie
                for c in pref_suff[start:]:
                    if c not in curr:
                        curr[c] = {}
                    curr = curr[c]
                    curr['max_idx'] = idx
                    
    def f(self, prefix: str, suffix: str) -> int:
        curr = self.trie
        to_search = suffix + '#' + prefix
        for c in to_search:
            if c not in curr:
                return -1
            curr = curr[c]
        return curr['max_idx']

        



# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)