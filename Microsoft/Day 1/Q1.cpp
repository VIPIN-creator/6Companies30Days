// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=14838d517bf558eb76aee1f55038286d&pid=704140&user=2019kucp1053
 int dp[1001][1001];
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int s = 0, i;
	    for(int i=0; i<n; i++) s+= arr[i];
	    
	    if(n==1 || s == 1) return s;
	    
	    for(int i=0; i<=n; i++){
	        for(int j=0; j<=s; j++) dp[i][j] = -1;
	    }
	    
	    
	   for(int i=0; i<=n; i++){
	       for(int j=0; j<=s/2; j++){
	           if(j==0){
	               dp[i][j] = 1;
	               continue;
	           }
	           if(i==0){
	               dp[i][j] = 0;
	               continue;
	           }
	           
	           if(j>= arr[i-1])dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	           else dp[i][j] = dp[i-1][j];
	           
	       }
	   }
	   
	   for(i=s/2; i>=0; i--){
	       if(dp[n][i]) break;
	   }
	   // cout << i << endl;
	    return s-2*i;
	} 
