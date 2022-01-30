 int dp[501][501];
    
    int solve(int i, int j, vector<int>& piles){
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans1 = solve(i+1, j, piles), ans2 = solve(i, j-1, piles), ans = 0;
        
        if(ans1 < ans2){
           ans = piles[i] + min(solve(i+2, j, piles), solve(i+1, j-1, piles)); 
        }
        else ans = piles[j] + min(solve(i+1, j-1, piles), solve(i, j-2, piles));
        
        return dp[i][j] = ans;
        
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), sum = 0, a = 0;
        for(auto x : piles) sum += x;
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++) dp[i][j] = -1;
        }
        
        a = solve(0, n-1, piles);
        
        return (a > sum-a);
        
    }
