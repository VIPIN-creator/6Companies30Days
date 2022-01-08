// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=e4bb6a3b0d652b361e3c1a3279f8ef4e&pid=701349&user=2019kucp1053
 vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int> dq;
        vector<int> ans(n-k+1);
         int j = 0, i;
         
        for(i=0; i<k; i++){
            while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
        }
        
       
        ans[j++] = arr[dq.front()];
        
        for(i = 1; i<n-k+1; i++){
            if(!dq.empty() && dq.front() < i) dq.pop_front();
            
            while(!dq.empty() && arr[dq.back()] <= arr[i+k-1]) dq.pop_back();
            dq.push_back(i+k-1);
            
            ans[j++] = arr[dq.front()];
            
        }
        
        return ans;
        
    }
