
    int lengthOfLongestAP(int A[], int n) {
          
        int ans = 1, d;
        
        vector<vector<int>>dp(1001, vector<int>(10001, 0)), dp2(501, vector<int>(501, 0));
        // int a[n] = A;
        
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                d =  A[j]-A[i];
                dp[j][d] = max(2, dp[i][d]+1);
                ans = max(ans, dp[j][d]);
            }
        }
        
        return ans;
      
    }
