vector<int> leaders(int a[], int n){
        // Code here
        int mx = a[n-1];
        vector<int> ans;
        for(int i=n-1; i>-1; i--){
             if(a[i] >= mx){
                ans.push_back(a[i]);
                mx = a[i];
            }
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
