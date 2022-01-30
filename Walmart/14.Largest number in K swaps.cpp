 static bool comp(string s1, string s2){
        if(s1.length() == s2.length()){
            for(int i=0; i<s1.length(); i++){
                if(s1[i] != s2[i]) return s1[i] < s2[i]; 
            }
            
            return 0;
        }
        return s1.length() < s2.length();
    }
    
    string solve(int i, int k, string str){
        if(k==0 || i == str.length()){
            // cout <<  str << endl; 
            return str;
        }
        
        
        
        int mx = str[i] - '0';
        for(int j = i+1; j<str.length(); j++){
            mx = max(mx, str[j]-'0');
        }
        
        if(mx == str[i]-'0'){
            return solve(i+1, k, str);
        }
        vector<string> ans;
        
        for(int j = i+1; j<str.length(); j++){
           if(mx == str[j]-'0'){
               string t = str;
               swap(t[j], t[i]);
               ans.push_back(solve(i+1, k-1, t));
           }
        }
        
        sort(ans.begin(), ans.end(), comp);
        
        
        
        return ans.back();
    }
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       return solve(0, k, str);
    }
