int missingNumber(const string& str)
{
    // Code here
    int len = str.length(), n, m, curr, i = 1, j = 0;
    
    for(; i<7 && i < str.length(); i++){
        n = stoi(str.substr(0, i));
        m = stoi(str.substr(i, log10(n+1)+1));
        if(m-n == 1) {
            if(2*i+log10(m+1)+1 > str.length()) break;
             n = stoi(str.substr(2*i, log10(m+1)+1));
             if(n-m == 2 || n-m == 1) break;
        }
        m = stoi(str.substr(i, log10(n+2)+1));
        if(m-n == 2){
            if(log10(m+1)+1+2*i > str.length()) break;
            n = stoi(str.substr(2*i, log10(m+1)+1));
            if(n-m==1) break;
        }
    }
    // cout << i << endl;
    if(i==7){
        return -1;
    }
    // cout << n << endl;
    len = i;
    n = stoi(str.substr(0, i));
    while(j<str.length()){
         if(j+len > str.length()) return -1;
        curr = stoi(str.substr(j, len));
        // cout << curr << endl;
        if(curr != n) break;
        
        j += len;
        // if(n%10 == 9) len += 1;
        n = n+1;
        len = log10(n)+1;
    }
    // cout << "yes";
     if(j==str.length()) return -1;
    
    int ans = n;
    n++;
    len = log10(n)+1;
    
    while(j<str.length()){
       if(j+len > str.length()) break;
       curr = stoi(str.substr(j, len));
        // cout << curr << endl;
        if(curr != n) break;
        
        j += len;
        // if(n%10 == 9) len += 1;
        n = n+1;
        len = log10(n)+1;
    }
    
    if(j<str.length()) return -1;
    
    return ans;
    
}
