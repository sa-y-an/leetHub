const int m = 1e9+7;
typedef long long ll;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        
        hor.push_back(h);
        hor.push_back(0);
        
        ver.push_back(0);
        ver.push_back(w);
        
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        
        
        ll maxWidth = 0;
        for( int i = 1; i < hor.size() ; i++){
            maxWidth = max(maxWidth, (hor[i]-hor[i-1])*1LL);
        }
        
        ll maxHeight = 0;
        for( int i =1 ; i < ver.size() ; i++){
            maxHeight = max(maxHeight, (ver[i] - ver[i-1])*1LL );
        }
        
        ll ans = ((maxWidth%m)*(maxHeight%m))%m;
        return ans;
    }
};