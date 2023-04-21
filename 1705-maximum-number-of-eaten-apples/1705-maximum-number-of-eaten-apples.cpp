typedef pair <int,int> pi;
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        
        priority_queue <pi , vector <pi> , greater <pi>> pq;
        int n = apples.size();
        int ans = 0 ;
        int i = 0;
        
        while( !pq.empty() || i < n ){
            int today = i+1;
            // first push if i < n
            if( i < n and days[i] > 0 )
                pq.push({days[i]+i,apples[i]});
            
            // exclue the apples that can't be eaten
            while( !pq.empty() and pq.top().first < today )// expired apples
                pq.pop();
            
            // bring the apple that can be eaten today
            if( !pq.empty()){
                pi temp = pq.top();
                pq.pop();
                ans++;
                temp.second--;
                if( temp.first > today and temp.second > 0 )
                    pq.push(temp);
            }
            i++;
        }
        
        return ans;
    }
};