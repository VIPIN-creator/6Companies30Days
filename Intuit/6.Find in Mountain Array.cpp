   int getPeak(MountainArray &mountainArr, int n){
        int s = 0, e = n-1, mid;
        
        while(s<e){
            mid = (s+e)/2;
            
            if(mountainArr.get(mid) > mountainArr.get(mid-1) && mountainArr.get(mid) > mountainArr.get(mid+1)){
                return mid;
            }
            
            if(mountainArr.get(mid) > mountainArr.get(mid-1) && mountainArr.get(mid) < mountainArr.get(mid+1)){
                s = mid;
            }
            else e = mid;
            
        }
        
        return mid;
        
    }
    
    int findLeft(MountainArray &mountainArr, int target, int peak){
        int s = 0, e = peak, mid, val;
        while(s<e-1){
            mid = (s+e)/2;
            
            // cout << s <<  " " << mid << " " << e << endl;
            
            val = mountainArr.get(mid);
            
            if(val == target) return mid;
            
            if(val > target){
                e = mid;
            }
            else s = mid;
            
        }
        
        return -1;
    }
    
    int findRight(MountainArray &mountainArr, int target, int peak, int n){
        int s = peak, e = n-1, mid, val;
        
        while(s<e-1){
            mid = (s+e)/2;
            val = mountainArr.get(mid);
            
            if(val == target) return mid;
            
            if(val > target){
                s = mid;
            }
            else e = mid;
        }
        
        return -1;
        
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), peak = getPeak(mountainArr, n);
         
        if(mountainArr.get(peak) == target) return peak;
        
        if(mountainArr.get(0) == target) return 0;
            
        if(mountainArr.get(peak) < target) return -1;
        
        int ans = findLeft(mountainArr, target, peak);

        if(ans != -1) return ans;
        
        ans =  findRight(mountainArr, target, peak, n);

        if(ans == -1)
        {
            if(mountainArr.get(n-1) == target) return n-1;
            else return -1;

        }
        
        return ans;
    }
