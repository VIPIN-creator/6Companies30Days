// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=94c2283ddf6a1af1ebdde6a6cda69474&pid=702128&user=2019kucp1053
vector<vector<int>> adj{vector<vector<int>>(10001, vector<int>())};
    vector<int> vis{vector<int>(10001, 0)};
    
     bool dfs(int u){
        if(vis[u] == 1) return 1;
        if(vis[u] == 2) return 0;
        
        vis[u] = 2;
        
        for(auto v : adj[u]){
            if(!dfs(v)) return 0;
        }
        
        vis[u] = 1;
        
        return 1;
    }

   
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    for(auto p: prerequisites){
	        adj[p.first].push_back(p.second);
	    }
	    
	    for(int i=0; i<N; i++){
	        if(!vis[i]){
	            if(!dfs(i)) return 0;
	        }
	    }
	    
	    return 1;
	}
