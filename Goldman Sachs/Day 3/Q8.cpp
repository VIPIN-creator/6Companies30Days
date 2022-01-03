// https://leetcode.com/problems/decode-ways/
// sol :- https://leetcode.com/submissions/detail/611887614/
// time :- o(n) space :- o(n)
 int dp[101];
    
    int solve(int n, string &s){
        if(n==0) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int ans;
        
        if(s[n-1]=='0'){
            if(n>1 && s[n-2]>'0' && s[n-2]<'3')
                return dp[n] =  solve(n-2, s);
            return dp[n] = 0;
        }
        
        if(n>1 && s[n-2] > '0' && (s[n-2]-'0')*10+(s[n-1]-'0') <= 26) 
            return dp[n] = solve(n-1, s) + solve(n-2, s);
        
        return dp[n] = solve(n-1, s);
        
    }
    
    int numDecodings(string s) {
        for(int i=0; i<101; i++) dp[i] = -1;
        return solve(s.length(), s);
    }
