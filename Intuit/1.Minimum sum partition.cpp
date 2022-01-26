	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int dp[1001][1001], ans = 0, sum = 0;
	    for(int i=0; i<n; i++) sum += arr[i];
	    
	    if(n==1 || sum == 1)return sum;
	    
	    for(int i=0; i<=n; i++){
	        for(int j=0; j<=sum/2; j++){
	            if(j == 0){
	                dp[i][j] = 1;
	                continue;
	            }
	            
	            if(i == 0){
	                dp[i][j] = 0;
	                continue;
	            }
	            
 
	           if(j>= arr[i-1])dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
	           else dp[i][j] = dp[i-1][j];
	           	            
	        }
	    }
	      
	   for(int i=sum/2; i>=0; i--){
	       if(dp[n][i]){
	           ans = max(ans, i);
	           break;
	       }
	   }
	            
	    return sum-2*ans;
	    
	} 
