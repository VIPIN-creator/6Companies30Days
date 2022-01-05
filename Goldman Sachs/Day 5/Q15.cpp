// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
// sol :- https://leetcode.com/submissions/detail/613420829/
// time :- o(n)
bool canArrange(vector<int>& arr, int k) {
        bool ans = 1;
        vector<int> mod(k, 0);
        for(auto x : arr){
            mod[(x%k + k)%k]++;
        }
        
        for(int i=0; i<k; i++){
            if(i==0 || (k%2==0 && i==k/2)){
                if(mod[i]%2) return 0;
                continue;
            }
            
            // cout << i << " " << mod[i] << " " << mod[k-i] << endl;

            if((mod[i] != mod[k-i])) return 0;
            
        }
        
        return 1;
    }
