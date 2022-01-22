 int Lis(vector<int> A){
       vector<int> lis;
       for(int i=0; i<A.size(); i++){
           if(lis.size() && A[i] <= lis.back()){
               auto it = lower_bound(lis.begin(), lis.end(), A[i]);
               lis[it-lis.begin()] = min(A[i], lis[it-lis.begin()]);
           }
           else lis.push_back(A[i]);
       }
       
       return lis.size();
   }
  
    int minInsAndDel(int A[], int B[], int N, int M) {
        
        int ans = 0;
        
        unordered_set<int> b;
        for(int i=0; i<M; i++){
            b.insert(B[i]);
        }
        
        vector<int> upd_a;
        for(int i=0; i<N; i++){
            if(b.find(A[i]) != b.end()) upd_a.push_back(A[i]);
            else ans++;
        }
        
        int lis = Lis(upd_a);
        // cout << lis << " " << upd_a.size() << " " << ans << endl;
        return ans + (upd_a.size()-lis) + (M-lis);
        
    }
