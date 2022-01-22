vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int sum = 0, l=0, r = 0;
        for(; l<n; l++){
            while(r <n && sum < s)sum += arr[r++];
            if(sum == s) return vector<int>({l+1, r});
            
            sum -= arr[l];
            
        }
        if(sum == s)return vector<int>({l, r});
        return {-1};
    }
