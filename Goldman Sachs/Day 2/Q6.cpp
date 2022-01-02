// https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Sol 1:- https://leetcode.com/submissions/detail/611326602/
// time :- o(n*n)
 bool check(string &s, string &t, int l, int n){
        int j=0; 
        while(j<n){
            if(t == s.substr(j, l)) j += l;
            else break;
        }
        
        return (j==n);
    }
    
    string gcdOfStrings(string str1, string str2) {
        int n = str1.length(), m = str2.length(), i;
        
        if(n>m){
            swap(n, m);
            swap(str1, str2);
        }
        
        string ans = "";
        
        for(i=n; i>0; i--){
            if(n%i) continue;
            ans = str1.substr(0, i);
            if(check(str1, ans, i, n) && check(str2, ans, i, m)) break;
        }
        if(!i) return "";
        return ans;
        
    }

// Sol 2 :- https://leetcode.com/submissions/detail/611331352/
// time :- O(n)
    string gcdOfStrings(string str1, string str2) {
       if(str1 + str2 == str2+str1) return str1.substr(0, __gcd(size(str1), size(str2)));
        return "";
    }

