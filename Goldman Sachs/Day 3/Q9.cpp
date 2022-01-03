// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=b5d1091048a89565c93fa05afb760940&pid=703607&user=2019kucp1053
// time:- o(n) 
 string printMinNumberForPattern(string S){
        // code here
        string s = S;
        int n= s.length(), i=0, j, k, val = 1;
        string ans(n+1, '?');
        
        while(i<n){
            if(s[i] == 'I'){
                ans[i] = val + '0';
                val++;
                i++;
                continue;
            }
            
            j = i;
            while(j<n && s[j] == 'D') j++;
            k = j;
            while(j>=i){
                ans[j] = val + '0';
                val++;
                j--;
            }
            i = k+1;
            
        }
        
        if(ans[n] == '?') ans[n] = val+'0';
        
        return ans;
       
        
    }
