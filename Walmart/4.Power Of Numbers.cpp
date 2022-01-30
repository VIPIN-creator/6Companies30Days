 int NumberOfPath(int a, int b)
    {
        //code here
        long long ans = 1;
        
        if(a<b) swap(a,b);
        
        for(int i=1; i<=b-1; i++){
            ans = (ans *(a+b-1-i))/i;
        }
        
        return ans;
    }
