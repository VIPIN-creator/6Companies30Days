 
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
      vector<vector<pair<int, double>>>adj(n);
        
       int m = edges.size(), u;
        for(int i=0; i<m; i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue<pi> pq;
        
        double d;
        vector<double>dis(n, 0.0);
        // fill(dis, dis+n, (double)0.0);
        
        pq.push({(double)1.0, start});
        dis[start] = 1.0;
        
        while(!pq.empty()){
            d = pq.top().first;
            u = pq.top().second;
            
            pq.pop();
            
            if(u == end) return dis[u];
            
            if(d < dis[u]) continue;
            
            for(auto v : adj[u]){
                if(d*v.second > dis[v.first]){
                    dis[v.first] = d*v.second;
                    // cout << dis[v.second] << " " << v.second << endl;
                    pq.push({dis[v.first], v.first});
                }
            }
            
            
        }

        return dis[end];
        
    }
