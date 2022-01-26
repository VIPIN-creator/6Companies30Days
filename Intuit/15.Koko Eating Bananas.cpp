    bool check(long long sp, vector<int> piles, int h){
        long long time = 0;
        
        for(auto x : piles){
            time += (x+sp-1)/sp;
        }
        // cout << time << " " << h << endl;
        if(time<=h) return 1;
        return 0;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 1, e  = 0, mid;
        for(auto x : piles) e += x;
        // e = (e+h-1)/h;
        int ans = e;
        // cout << e << endl;
        while(s <= e){
            mid = s + (e-s)/2;
            if(check(mid, piles, h)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        
        return ans;
        
    }
