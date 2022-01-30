   int dp[205][205];
    
//     int solve(int i, int j){
//         if(i>=j) return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//        s = i, e = j, mid;
        
//         while(s<=e){
//             mid = s+(e-s)/2;
//             ans1 = solve(i, mid-1);
//             ans2 = solve(mid+1, j);
            
//             if(ans1 > ans2){
                
                
//             }
            
//         }
        
//         return dp[i][j] = ans;
        
//     }
    
    int getMoneyAmount(int n) {
        
//         for(int i=0; i<=n; i++){
//             for(int j=0; j<=n; j++) dp[i][j] = 0;
//         }
        
        for(int i=n; i>=1;  i--){
          for(int j=1; j<=n; j++){
              if(i>=j){
                  dp[i][j] = 0;
                  continue;
              }
              
              int ans= INT_MAX, ans1, ans2;
              
              for(int k=i; k<=j; k++){
                 
                  ans1 = dp[i][k-1];
                  ans2 = dp[k+1][j];
                  ans = min(ans, max(ans1, ans2)+k);
              }
              
              dp[i][j] = ans;
          }
        }
        
//          for(int i=0; i<=n; i++){
//             for(int j=0; j<=n; j++) cout << dp[i][j] << " ";
//              cout << endl;
//         }
        
       return dp[1][n]; 
    }
