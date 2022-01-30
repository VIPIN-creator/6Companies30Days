 int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        
        vector<pair<int, int>> a(n);
        for(int i=0; i<n; i++){
            a[i].ff = efficiency[i];
            a[i].ss = speed[i];
        }
        
        sort(a.begin(), a.end());
        
        long long sum = 0, ans = 0, M = 1000000007;
        
        for(int i=n-1; i>=n-k; i--){
           pq.push(a[i].ss);
            sum = (sum + a[i].ss);
            ans = max(ans, ((a[i].ff)*(sum)));
        }
        
        // ans = msum*a[n-k].ff;
        
        for(int i=n-k-1; i>=0; i--){
            // cout << (*s.begin()) << " ";
            
            if(a[i].ss > pq.top()){
                sum = (  (sum) - pq.top() + a[i].ss);
               pq.pop();
                pq.push(a[i].ss);
            }
            
            ans = max(ans, ( (a[i].ff) * (sum)));
        }
        
        return ans%M;
        
    }
