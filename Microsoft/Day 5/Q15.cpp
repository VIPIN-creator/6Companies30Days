// https://practice.geeksforgeeks.org/problems/alien-dictionary/1/
 
    int dfs(int u, string &ans, vector<int> &vis,  vector<vector<int>> &adj)
    {
        vis[u] = 1;
        for(auto v : adj[u]){
            if(!vis[v]) dfs(v, ans, vis, adj);
        }
        
        ans.push_back('a'+u);
        
        
        return 1;
        
    }
    
    string findOrder(string dict[], int N, int K) {
     
        vector<vector<int>> adj(26);
        // vector<bool> mark(26, 0);
        
        // map<char, set<char>> mp;
          for(int i=0; i<N-1; i++){
            
            int j = i+1;
           
                int k = 0, n = dict[i].length(), m = dict[j].length();

                while(k<min(dict[i].length(), dict[j].length()) && dict[i][k] == dict[j][k]){
                    k++;
                }
                
                if(k == min(m, n)){
                    if(n<=m)
                     continue;
                     return "";
                 }

                adj[dict[j][k]-'a'].push_back(dict[i][k]-'a');
                
                // mp[dict[j][k]].insert(dict[i][k]);
        }

        vector<int> vis(26, 0);
        string ans, add;
        
        bool invalid;

        for(int i=0; i<K; i++){
            if(!vis[i]){
                invalid = 1;

                invalid = dfs(i, ans, vis, adj);

                if(!invalid) return "";
               
                add += ans;
                ans.resize(0);
            }
        }

     
        return add;
    
        
        
    }
