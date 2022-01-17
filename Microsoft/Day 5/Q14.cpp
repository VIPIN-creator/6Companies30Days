// https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/
 int minSteps(int D){
        // code here
        int ans = 0, sum = 0;
        while(sum < D){
            ans++;
            sum += ans;
        }
        
        if( (sum-D)%2 == 0) return ans;
        
       ans++;
       if((sum+ans-D)%2 == 0) return ans;
        
        return ans+1;
    }
