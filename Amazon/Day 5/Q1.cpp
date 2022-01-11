// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=11e29c5572e96aeff78432b274782057&pid=704532&user=2019kucp1053
// time:- O(nk) space:- (2nk)
int dp[2][1001][101];
    
    int solve(int i, bool state, int k,  int prices[], int n){
        if(i>= n || k == 0) return 0;
        
        if(dp[state][i][k] != -1) return dp[state][i][k];
        
        if(state){
            return dp[state][i][k] = max(prices[i]+solve(i+1, 0, k-1, prices, n), solve(i+1, 1, k, prices, n));
        }
        return dp[state][i][k] = max(solve(i+1, 1, k, prices, n)-prices[i], solve(i+1, 0, k, prices, n)); 
        
    }
  
    int maxProfit(int K, int N, int A[]) {
        // code here
         for(int i=0; i<2; i++){
            for(int j=0; j<N; j++){
                for(int l=0; l<=K; l++) dp[i][j][l] = -1;
            }
        }
        
        return solve(0, 0, K, A, N);
    }
