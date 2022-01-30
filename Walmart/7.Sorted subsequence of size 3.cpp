vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        vector<int> mx(N), mn(N), ans;
        
        for(int i=0; i<N; i++){
            if(i)mn[i] = min(mn[i-1], arr[i]);
            else mn[i] = arr[i];
            
            if(i)mx[N-i-1] = max(mx[N-i], arr[N-i-1]);
            else mx[N-i-1] = arr[N-i-1];
            
        }
        
        for(int i=0; i<N; i++){
            // cout << mn[i] << " " << arr[i] << " " << mx[i] << endl;
            if(arr[i] != mx[i] && arr[i] != mn[i]){
                return vector<int>({mn[i], arr[i], mx[i]});
            }
        }
        
        
        
        return {};
        
    }
