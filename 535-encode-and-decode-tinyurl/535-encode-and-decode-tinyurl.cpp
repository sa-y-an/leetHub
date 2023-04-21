class Solution {
    unordered_map <string, string> dict;
    string lastAdded;
public:
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        if( lastAdded.size() == 0  ) lastAdded = "a";
        else {
            if( lastAdded.back() == 'z') lastAdded.push_back('a');
            else {
                int n = lastAdded.size();
                lastAdded[n-1] += 1;
            }
        }
        
        dict[lastAdded] = longUrl;
        return lastAdded;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dict[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));