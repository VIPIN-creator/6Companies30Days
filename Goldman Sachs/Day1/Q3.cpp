// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/
// Sol 1: Use log(product of all x) = sum of log[x] and then make a prefix sum array of log[nums[i]], then apply binary search for each i and find largest j such that prefix[j]-prefix[i] < k.
// time :- O(n) space:- O(n)

// sol2 : sliding window
// https://leetcode.com/submissions/detail/611207243/

 int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r= 0, prev_r = 0, n = nums.size(), ans = 0, prod = 1;
        if(k<=1) return 0;
        
       for(r=0; r<n; r++){
           prod *= nums[r];
           while(prod>=k) prod = prod/nums[l++];
           ans += r-l+1;
       }
        
        return ans;
  }
