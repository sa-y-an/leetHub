class Solution {  
public:
    
    bool visited[202][202];
    
    int X, Y;
    
    bool canVisitAtlantic(vector <vector <int>> &heights, int x , int y ){
        
        if( x == X-1 or y == Y-1 ) return true;
        if( x >= X or y >= Y or x < 0 or y < 0 ) return false;
        if( visited[y][x] ) return false;
        
        visited[y][x] = true;
        
        if( x+1 < X and heights[y][x+1] <= heights[y][x] ) 
            if( canVisitAtlantic(heights,x+1, y) ) return true;   
        if( y+1 < Y and heights[y+1][x] <= heights[y][x] ) 
            if( canVisitAtlantic(heights,x, y+1) ) return true;
        if (x-1 >= 0 and heights[y][x-1] <= heights[y][x]) 
            if( canVisitAtlantic(heights,x-1, y) ) return true;
        if (y-1 >= 0 and heights[y-1][x] <= heights[y][x]) 
            if( canVisitAtlantic(heights,x, y-1) ) return true;
        return false;        
    }
    
    bool canVisitPacific(vector <vector <int>> &heights, int x, int y){    
        
        if( x == 0 or y == 0 ) return true;
        if( x < 0 or y < 0 or x >= X or y >= Y) return false;
        if( visited[y][x] ) return false;
        
        visited[y][x] = true;

        
        
        if (x-1 >= 0 and heights[y][x-1] <= heights[y][x]) 
            if( canVisitPacific(heights,x-1, y) ) return true;
        if (y-1 >= 0 and heights[y-1][x] <= heights[y][x]) 
            if( canVisitPacific(heights,x, y-1) ) return true;
        if( x+1 < X and heights[y][x+1] <= heights[y][x] ) 
            if( canVisitPacific(heights,x+1, y) ) return true;   
        if( y+1 < Y and heights[y+1][x] <= heights[y][x] ) 
            if( canVisitPacific(heights,x, y+1) ) return true;
        
        return false;
        
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        X = heights[0].size() , Y = heights.size();
        memset(visited,false, sizeof(visited));
        vector <vector <int> > ret;
        for( int y = 0 ; y < Y ; y++){
            for( int x = 0 ; x < X ; x++){
                memset(visited,false, sizeof(visited))  ;
                if( ( x == 0 or y == 0 or canVisitPacific(heights,x,y)) ){
                    memset(visited,false, sizeof(visited));
                    if( x == X-1 or y == Y-1 or canVisitAtlantic(heights,x,y)){
                        ret.push_back({y,x});   
                    }
                } 
            }
        }
        
        // cout<<canVisitAtlantic(heights,1,2)<<" ";
        
        return ret;
    }
};