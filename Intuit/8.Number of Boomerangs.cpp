 long long cal(int i, int j, vector<vector<int>>& points){
        long long d1 = 0, d2  = 0;
        
        d1 = (points[i][0]-points[j][0]);
        d1 *= d1;
                    
        d2 = (points[i][1]-points[j][1]);
        d2 *= d2;
                    
            
           return d1 + d2; 
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0, j, k, i;
        
        long long d1 = 0, d2 = 0, ans1, ans2;
        
        for(i=0; i<n; i++){
            map<long long, long long> mp;
            if(i==j) continue;
            for(j=0; j<n; j++){
              
                mp[cal(i, j, points)]++;
               
            }
            for(auto x : mp){
                // cout << mp[x.first] << " "; 
                ans += mp[x.first]*(mp[x.first]-1);
            }
            // cout << endl;
        }
        
        return ans;
    }
