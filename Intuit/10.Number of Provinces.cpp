
    bool v[201];
    
    void dfs(int i, vector<vector<int>>& isConnected) {
       
        v[i] = 1;
        
        for(int j=0; j<isConnected.size(); j++){
            if(isConnected[i][j] && v[j]==0) dfs(j, isConnected);
        }
        
        return ;
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
       int ans = 0, n = isConnected.size();
        for(int i=0; i<n; i++){
          
            if(!v[i]){
                dfs(i, isConnected);
                ans++;
            }
               
        }
        
        return ans;
    }
