// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=76c50ba821f5cdf245a6050ecb1cdd7f&pid=707042&user=2019kucp1053
//  time :- o(n) space :- o(k)
 vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int> dq;
        int i = 0, j = 0;
        vector<int> ans;
        
        while(i+k<=n){
            if(j-i+1<=k){
                while(!dq.empty() && dq.back() < arr[j]) dq.pop_back();
                dq.push_back(arr[j++]);
            }
            else{
                ans.push_back(dq.front());
                if(arr[i] == dq.front()) dq.pop_front();
                i++;
            }
        }
        
        return ans;
    }

// Sol 2:- using multiset time :- o(nlogk) space :o(k)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> ans;
        int mx = 0, i, j, n = nums.size();
            
        multiset<int> s;
        
        for(i=0; i<k; i++){
           s.insert(nums[i]);
        }
        ans.push_back(*(s.rbegin()));
        
        i = 1;
        while(i<n-k+1){
            
            s.erase(s.find(nums[i-1]));
            s.insert(nums[i+k-1]);
            
            ans.push_back(*(s.rbegin()));
            
            i++;
        }
        
        return ans;
        
    }
