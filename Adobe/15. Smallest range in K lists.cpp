#define ff first
#define ss second
#define pi pair<int, int>
#define pii pair<int, pair<int, int>>
class Solution{
    public:
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
         
        int r, c, mx = 0, val;
        pair<int, int> ans;
        priority_queue<pii, vector<pii>, greater<pii> >pq;
        for(int i=0; i<k; i++){
            pq.push({a[i][0], {i, 0}});
            mx = max(mx, a[i][0]);
        }
        
        ans = {pq.top().ff, mx};
        
        r = pq.top().ss.ff;
        c = pq.top().ss.ss;
        
        while(c < n-1){
            val = pq.top().ff;
            r = pq.top().ss.ff;
            c = pq.top().ss.ss; 
            pq.pop();
            
            
            if(ans.ss-ans.ff > mx-val){
                ans = {val, mx};
            }
            
            if(c+1<n){pq.push({a[r][c+1], {r, c+1}});
            if(mx < a[r][c+1]) mx = a[r][c+1];
            }
        }
      
        
        return ans;
         
    }
};
