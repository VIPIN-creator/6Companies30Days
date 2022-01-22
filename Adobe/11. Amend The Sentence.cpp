string amendSentence (string s)
    {
        // your code here
        string ans;
        int i = 0, n = s.length(), j = 0;
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
        
        while(i<n){
            j = i;
            while(j<n && s[j]>='a' && s[j] <= 'z'){ 
                ans.push_back(s[j]);
                j++;
            }
            
            if(j == n) break;
            
            ans.push_back(' ');
            
            s[j] = tolower(s[j]);
            
            i = j;
            
        }
        
        return ans;
        
    }
