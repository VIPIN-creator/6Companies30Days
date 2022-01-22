 int equalPartition(int N, int arr[])
    {
        // code here
        bool dp[101][50001];
        int sum = 0, i = 0;
        for(; i<N; i++) sum += arr[i];
        
        if(sum%2) return 0;
        
        for(i=0; i<=N; i++){
            for(int j=0; j<=sum/2; j++){
                if(j==0){
                    dp[i][j] = 1;
                    continue;
                }
                
                if(i==0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(arr[i-1]<=j) dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else dp[i][j] = dp[i-1][j] ;
                
            }
        }
        
        return dp[N][sum/2];
        
    }
