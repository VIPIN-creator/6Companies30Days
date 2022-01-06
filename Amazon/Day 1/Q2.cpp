// https://leetcode.com/problems/longest-mountain-in-array/
// Sol :- https://leetcode.com/submissions/detail/614070042/
// time :- o(n) 
int longestMountain(vector<int>& arr) {
        int i = 0, n = arr.size(), ans = 0, cnt = 0, j;
        
        while(i<n-1){
            cnt = 0;
            j = i;
            while(i<n-1 && arr[i] < arr[i+1]) i++; 
            
            if(j-i == 0){
                i++; continue;
            }
            cnt += i-j;
            
            j = i;
            while(i<n-1 && arr[i] > arr[i+1]) i++; 
            
            if(j-i == 0){
                i++; continue;
            }
            cnt += i-j+1;
            
            ans = max(ans, cnt);
        }
        
        return ans;
        
    }
