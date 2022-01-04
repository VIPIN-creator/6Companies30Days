// https://leetcode.com/problems/minimum-size-subarray-sum/
// Sol :- https://leetcode.com/submissions/detail/612709881/
// time :- o(nlogn) space :- o(n)

 int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), i = 0, ans = n+1, add = 0;
        for(i=0; i<n; i++){
            if(i) nums[i] += nums[i-1];
        }
        
        for(i=0; i<n; i++){
            if(i) add= nums[i-1];
            auto it = lower_bound(nums.begin()+i, nums.end(), target+add);
            if(it == nums.end()) continue;
            
            ans = min(ans, (int)(it-nums.begin()) - i + 1);
            
        }
        
        if(ans == n+1) return 0;
        return ans;
    }

// Sol 2: 
// time:- o(n) space:- o(1)
// will do later
