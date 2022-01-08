// https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=fb0ba2f316346092ceb7ebc8d16a8d83&pid=705397&user=2019kucp1053
 int brkt[26][26];
    int dp[26][26];
    // string ans;
    
    string para(int i, int j){
        if(i>=j) return "";
        
        if(i+1 == j){
          return (string(1, 'A' + i));
            
        }
        
        
        return ('('+para(i, brkt[i][j])+para(brkt[i][j], j) + ')');
       
        
    }
    
    int solve(int p[], int n, int i, int j){
        if(i>=j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mn = INT_MAX, id, temp;
        
        for(int k=i+1; k<j;k++){
            temp = solve(p, n, i, k) + solve(p, n, k, j) + p[i]*p[k]*p[j];
            if(temp < mn){
                mn = temp;
                id = k;
            }
        }
        
        brkt[i][j] = id;
        
        return dp[i][j] = mn;
        
    }
    
    string matrixChainOrder(int p[], int n){
        // code here
        for(int i=0; i<n; i++){
            for(int j= 0; j<n;j++) dp[i][j] = -1;
        }
        
        solve(p, n, 0, n-1);
        return para(0, n-1);
        
        
        
    }
