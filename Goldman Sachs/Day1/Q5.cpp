// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/
// sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=c463eacc27ea9069e8e94c386ee66b8b&pid=703093&user=2019kucp1053
// time :- o(n)
	ull getNthUglyNo(int n) {
	    // code here
	    int i = 1,c2 = 0, c3 = 0, c5 = 0;
        vector<ull> ans(n);
        ans[0] = 1;
        for(; i<n; i++){
            ans[i] = min({ans[c2]*2, ans[c3]*3, ans[c5]*5});
            if(ans[i] == ans[c2]*2) c2++;
            if(ans[i] == ans[c3]*3) c3++;
            if(ans[i] == ans[c5]*5) c5++;

        }
        
        return ans[n-1];
	}
