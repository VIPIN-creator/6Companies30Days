// https://leetcode.com/problems/rotting-oranges/
// time:- o(N*M) space:- O(N*M)
// Sol :- https://leetcode.com/submissions/detail/616760287/

int m, n;
    
    bool check(int i, int j){
        if(i<0 || j<0 || i>= m || j>= n) return 0;
        return 1;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        
        m = grid.size();
        n = grid[0].size();
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        
        int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
    
        // if(q.size() == 0) return 0;
        
        int l, ans = 0 ;
        
        bool donothing = 1;
        
        while(!q.empty()){
            l = q.size();
            
            // / ans++;
            donothing = 1;
            for(int i=0; i<l; i++){
                pair<int, int> p = q.front(); q.pop();
                
                for(int k = 0; k<4; k++){
                    if(!check(p.first+dx[k], p.second+dy[k]) || grid[p.first+dx[k]][p.second+dy[k]] != 1) continue;
                    
                    grid[p.first+dx[k]][p.second+dy[k]] = 2;
                    
                    donothing = 0;
                    
                    q.push({p.first+dx[k], p.second+dy[k]});
                    
                }
                
            }
            if(!donothing) ans++;
            
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) if(grid[i][j] == 1) return -1; 
        }
        
        return ans;
    }
