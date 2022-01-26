 int a[201][201];
    int p[201][201];
    
    int dfs(int i, int j, vector<vector<int>>& heights, bool t){
        if(t && p[i][j]) return p[i][j];
        if(!t && a[i][j]) return a[i][j];

        
        if(t) p[i][j] = 1;
        if(!t) a[i][j] = 1;
        
        int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
        
       
            if(i>0 && heights[i-1][j] <= heights[i][j]){
                x1 = dfs(i-1, j, heights, t);
                if(x1 == 2) {

                    if(t)return p[i][j] = 2;
                    else return a[i][j] = 2;    
                }
            }
                                                                                                                                                                    
             if(j<heights[0].size()-1 && heights[i][j+1] <= heights[i][j]){
                x2 = dfs(i, j+1, heights, t);
                if(x2 == 2) {
                if(t)return p[i][j] = 2;
                else return a[i][j] = 2;    
                }
            }
            
             
            if(i<heights.size()-1 && heights[i+1][j] <= heights[i][j]) {
                 x3 = dfs(i+1, j, heights, t);
                if(x3 == 2){
                if(t)return p[i][j] = 2;
                else return a[i][j] = 2;    
                }
            }
                        
            
            if(j>0 && heights[i][j-1] <= heights[i][j]){
                 x4 = dfs(i, j-1, heights, t);
                if(x4 == 2){
                if(t)return p[i][j] = 2;
                else return a[i][j] = 2;    
                }
            }
       
       if(t)return p[i][j] = 0;
        else return a[i][j] = 0;    
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size(), m = heights[0].size(), mx, mxr;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                a[i][j] = p[i][j] = 0;
                if(i==0 || j == 0){
                    p[i][j] = 2;
                 }
                if(i == n-1 || j == m-1){
                    a[i][j] = 2;
                }
            }
        }

        vector<vector<int>> ans;
        
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(a[i][j] == 0){
                  dfs(i, j , heights, 0);
               }
               if(p[i][j] == 0){
                   dfs(i, j, heights, 1);
               }
               
               if(p[i][j] == 2 && a[i][j] == 2) ans.push_back(vector<int>({i, j}));
              }
           }
       return ans;
        
    }   
