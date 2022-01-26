bool check(int wt, vector<int>& weights, int days){
        int d = 0, i = 0, n = weights.size(), s = 0;
    
        while(i<n){
            s = 0;
            while(i<n && s+weights[i] <= wt){
                s += weights[i];
                i++;
            }
            
            d++;
            if(d>days) return 0;
        }    
        
        return 1;
        
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(), s = 0, e = 0, mid, ans;
        for(auto x : weights) e += x;
        
        while(s<=e){
            mid = e+(s-e)/2;
            
            if(check(mid, weights, days)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
            
        }
        
        return ans; 
        
    }
