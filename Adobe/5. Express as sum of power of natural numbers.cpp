long long dp[1001][1001];

    
    long long solve(long long N, long long j, long long x){
    
        if(N==0) return 1;
         long long p = pow(j, x);
        
        if(p > N) return 0;
       
        
        
        if(dp[N][j] != -1) return dp[N][j];
        
        
        return dp[N][j] = solve(N-p, j+1, x) + solve(N, j+1, x);
        
    }
    
    long long numOfWays(int n, int x)
    {
        // code here
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=n; j++) dp[i][j] = -1;
        // }
      
        long long m=pow(n, 1.0/x), p;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i == 0){
                    dp[i][j] = 1;
                    continue;
                }
                
                if(j==0) {dp[i][j]=0; continue;}
                
                p = pow(j, x);
                if(p>i){
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                
                
                dp[i][j] = dp[i-p][j-1] + dp[i][j-1];
            }
        }
        return dp[n][m];
    }
