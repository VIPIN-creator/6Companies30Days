// https://leetcode.com/problems/decode-string/
// Sol :- https://leetcode.com/submissions/detail/612692302/
// time :- o(n) space :- o(1)
string solve(int &i, string s){
        if(i>= s.length()) return "";
        string temp;
        
        while(s[i]>='a' && s[i]<='z'){
            temp += s[i++];
        }
        
        if(s[i] == ']'){
            // cout << temp << " " << i + 1 << endl;
            i++; return temp;
        }
        
        int cnt =0;
        while(s[i]>='0' && s[i]<='9'){
            cnt = cnt*10 + (s[i]-'0');
            i++;
        }
        i++;
        string temp2 = solve(i, s);
        
        for(int j=0; j<cnt; j++) temp += temp2;
        // cout << cnt << " " <<  i << endl;
        return temp + solve(i, s);
        
    }
    
    string decodeString(string s) {
        int i = 0;
        return solve(i, s);
        
    }
