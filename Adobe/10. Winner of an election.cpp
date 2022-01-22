 static bool comp(string s1, string s2){
        int i = 0, j = 0, n1 = s1.length(), n2 = s2.length();
        
        while(i<n1 && j<n2){
            if(s1[i] != s2[j]) break;
            i++; j++;
        }
        
        if(i == n1 || j == n2) return n1<n2;
        
        return s1[i]<s2[j];
        
    }
    
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        sort(arr, arr+n);
        vector<pair<int, string>> votes;
        
        int i = 0, j;
        while(i<n){
            j = i;
            while(j<n && arr[i] == arr[j]) j++;
            
            votes.push_back({j-i, arr[i]});
            
            i = j;
            
        }
        
        sort(votes.rbegin(), votes.rend());
        
        vector<string> max_votes;
        
        for(auto c : votes){
            if(c.first == votes[0].first){
                max_votes.push_back(c.second);
            }
            else break;
        }
        
        sort(max_votes.begin(), max_votes.end(), comp);
        
        return {max_votes[0], to_string(votes[0].first)};
        
        
    }
