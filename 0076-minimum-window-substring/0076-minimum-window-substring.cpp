const int INF = 1e9+7;
class Solution {
public:
    
    bool isMatch(vector<int> &smap,vector <int> &tmap){
        for( int i = 0 ; i < 60 ; i++){
            if( smap[i] < tmap[i] )
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        vector <int> tmap(60,0) , smap(60,0);
        for( char ch : t ) tmap[ch-'A']++;
        const int n = s.size();
        deque <int> q;
        int mini = INF;
        int start = -1;
        for( int i = 0 ; i < n ; i++){
            if( tmap[s[i]-'A'] == 0 ) continue;
            smap[s[i]-'A']++;
            q.push_back(i);
            while( isMatch(smap, tmap) ){
                int curr = q.back() - q.front() + 1;
                if( curr < mini ){
                    mini = curr;
                    start = q.front();
                }
                smap[s[q.front()]-'A']--;
                q.pop_front();
            }
        }
        
        if( mini == INF ) return "";
        return s.substr(start, mini);        
    }
};