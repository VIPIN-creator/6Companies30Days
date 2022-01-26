 vector<vector<int>>adj{vector<vector<int>>(2001, vector<int>())};
    int v[2001];
    
    int dfs(int i, vector<int> &ans){
        if(v[i]) return v[i];
        
        v[i] = 2;
        
        for(auto u : adj[i]){
            if(dfs(u, ans) == 2) return 2;
        }
        
        v[i] = 1;
        
        ans.push_back(i);
        
        return 1;
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto x : prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(v[i] == 0){
                if(dfs(i, ans) == 2) return {};
            }
        }
        
        return ans;
        
    }
