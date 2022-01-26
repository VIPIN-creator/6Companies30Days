 int dis[101][101], ans = -1, dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0}, n;
    
    bool check(int i, int j){
        if(i<0 || i>=n || j>=n || j<0) return 0;
        return 1;
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid){
        int d  = dis[i][j]+1;
        
        for(int k=0; k<4; k++){
            if(check(i+dx[k], j+dy[k]) && grid[i+dx[k]][j+dy[k]] != 1 && dis[i+dx[k]][j+dy[k]] > d ){
                dis[i+dx[k]][j+dy[k]] = d;
                dfs(i+dx[k], j+dy[k], grid);
            }
        }
        
        return 0;
        
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                if(!grid[i][j])dis[i][j] = 501;
                else dis[i][j] = 0;
            }
                
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    dis[i][j] = 0;
                    dfs(i, j, grid);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0)
                    ans = max(ans, dis[i][j]);
            }
        }
        if(ans == 501) return -1;
        return ans;
        
    }
