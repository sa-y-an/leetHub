class Solution {
    unordered_map <string,int> seen;
    vector <vector <int>> adjList;
public:
    
    void buildGraph(vector<string>& words){

        int n = words.size();
        for( int i = 0 ; i < n ; i++){
            
            string &s = words[i];
            string temp = s;
            // traverse every letter
            for( int j = 0 ; j < temp.size() ; j++){
                // traverse every alphabet
                for( char ch = 'a' ; ch <= 'z' ; ch++ ){
                    if( ch == s[j] )
                        continue;
                    temp[j] = ch;
                    if( seen.count(temp) ){
                        int a = seen[temp], b = i;
                        adjList[a].push_back(b);
                        adjList[b].push_back(a);
                    }
                    temp[j] = s[j];
                }
            }
            
            seen[s] = i;
        }
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        
        if( find(words.begin(),words.end(),beginWord) == words.end() )
            words.push_back(beginWord);
        
        int n = words.size();
        adjList.resize(n);
        buildGraph(words);
        
        if(!seen.count(endWord))
            return 0;
        int start = seen[beginWord], end = seen[endWord];
        queue <int> q;
        q.push(start);
        int level = 1;
        
        vector <bool> visited(n,false);        
        while( !q.empty() ){
            
            int sz = q.size();
            for( ; sz-- ; q.pop() ){
                int par = q.front();
                visited[par] = true;
                for( auto child : adjList[par] ){
                    if( visited[child] ) continue;
                    if( child == end )
                        return level+1;
                    q.push(child);
                    
                }
            }
            level++;
        }
        
        return 0;
    }
};