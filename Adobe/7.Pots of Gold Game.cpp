
    int dp[501][501];
    
    int solve(int i, int j, vector<int>&A){
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans1 = solve(i+1, j, A), ans2 = solve(i, j-1, A);
        
        if(ans1<ans2){
            dp[i][j] = A[i-1];
            if(solve(i+2, j, A) < solve(i+1, j-1, A))
                dp[i][j] += solve(i+2, j, A);
            else dp[i][j] += solve(i+1, j-1, A);
            
        }
        else {
             dp[i][j] = A[j-1];
             if(solve(i, j-2, A) < solve(i+1, j-1, A))
                dp[i][j]  += solve(i, j-2, A);
             else dp[i][j] += solve(i+1, j-1, A);
        }
       
        
        return dp[i][j] ;
        
    }

    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    for(int i=0; i<=n; i++){
	        for(int j=0; j<=n; j++) dp[i][j] = dp[i][j] = -1;
	    }
	    
	   return solve(1, n, A);
	   
    }
