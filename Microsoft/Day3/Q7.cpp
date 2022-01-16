 int n , m, ans = 0;
    
    vector<vector<int>> vis{vector<vector<int>>(501, vector<int>(501, 0))};
    
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    bool check(int i, int j){
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j]) return 0;
        return 1;
    }
    
    int dfs(int i, int j, int &cnt, vector<vector<int>>& grid){
        vis[i][j] = 1;
        cnt++;
       
        
        for(int k=0; k<8; k++){
            if(check(dx[k]+i, dy[k]+j) && grid[dx[k]+i][dy[k]+j]){
                
                dfs(dx[k]+i, dy[k]+j, cnt, grid);
            }
        }
        
        return 0;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        n  = grid.size();
        m  = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){\
            int cnt = 0;
                if(vis[i][j] == 0 && grid[i][j] == 1) dfs(i, j, cnt, grid);
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
