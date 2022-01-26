 int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0, cnt, i=0, j ;
    
        vector<int> zero(n, 0);
        
        for(int i=0; i<n; i++){
            cnt = 0;
            for(int j=0; j<n; j++){
                if(grid[i][j]) cnt = 0;
                else cnt++;
            }
            zero[i] = cnt;
            // cout << zero[i] << " ";
 
        }
      i = 0;  
        while(i<n){
            j = i;
            while(j<n && zero[j] < n-i-1) j++;
            
            if(j==n)return -1;
            
            while(j != i){
                // cout << zero[j]  << " " << zero[j-1] << endl;
                swap(zero[j], zero[j-1]);
                j--;
                ans++;
            }
            // cout << zero[j] << endl;
            i++;
        }
        
        return ans;
            
        
    }
