int atoi(string str) {
        //Your code here
        string s = str;
        int i=0, n = s.length();
        while(i<n && s[i] == ' ') i++;
        
        if(i==n) return -1;
        
        int ans = 0;
        bool neg = 0;
        if(s[i] == '-'){
          neg = 1; i++;  
        } 
        else if(s[i] == '+') i++;
        
        while(i<n && s[i]>= '0' && s[i] <= '9'){
            if(neg){
               ans = ans*10 - (s[i]-'0');
                
            }
            else ans = ans*10 + (s[i]-'0');
            i++;
        }
        
        if(i<n) return -1;
        
        return ans;
        
    }
