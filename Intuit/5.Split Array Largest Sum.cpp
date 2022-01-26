bool check(int sum, vector<int>& nums, int m){
        int i =0, n = nums.size(), sb = 0, s = 0;
        while(i<n){
            s = 0;
            while(i<n && s+nums[i] <= sum){
                s += nums[i];
                i++;
            }
            
            sb++;
            if(sb > m) return 0;
        }
        
       return 1;
        
    }
  
    int splitArray(vector<int>& nums, int m) {
     
    int sum, s, e, mid, n=nums.size(), ans;
        
        for(auto x : nums) sum += x;
        
        s = (sum+m-1)/m;
        e =  sum;
        
        while(s<=e){
            mid = s + (e-s)/2;
            
            if(check(mid, nums, m)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
            
        }
       
     return ans;   
    }
