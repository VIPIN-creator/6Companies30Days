// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
 vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int l=j+1; l<n; l++){
                   
                   auto it = lower_bound(arr.begin()+l+1, arr.end(), k- (arr[i]+arr[j]+arr[l]));
                   
                   if(it == arr.end() || arr[it-arr.begin()] != k- (arr[i]+arr[j]+arr[l]))
                   continue;
                   
                   s.insert(vector<int>({arr[i], arr[j], arr[l], k- (arr[i]+arr[j]+arr[l])}));
                   
                  if(l<n-1 && arr[l] == arr[l+1]) l++;
                }
                
                if(j<n-1 && arr[j] == arr[j+1])j++;
            }
            if(i<n-1 && arr[i] == arr[i+1])i++;
        }
        
        for(auto x : s){
            ans.push_back(x);
        }
        
        return ans;
        
    }
