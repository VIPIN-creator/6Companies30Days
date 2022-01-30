class compare {
public:
    bool operator() (string &a, string &b) {
        
        if(a.size() != b.size()) return b.size() < a.size();
        
        return b < a; // because if comp(a, b) return true then comp(b, a) must return false    . 

    }
};

class Solution {
public:
        // T = O(KlogK*M + (N-K)log(N-k)*M)
    
    bool comp(string a, string b){
         if(a.length() < b.length()) return 1;
        
        if(a.length() > b.length()) return 0;
        
        
        int i=0;
        
        for(; i<a.length(); i++){
            if(a[i]-'0' > b[i]-'0') return 0; 
            
            if(a[i]-'0' < b[i]-'0') return 1;
        }
        
        return 0; // because if comp(a, b) return true then comp(b, a) must return false    . 

    }
    
    
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        // sort(nums.begin(), nums.end(), compare);
        
        priority_queue<string, vector<string> , compare> pq;
        
        int i = 0, n = nums.size();
        for(i=0 ; i<k; i++){
            pq.push(nums[i]);
        }
        
        for(; i<n; i++){
            if(comp(pq.top(), nums[i]) == 1){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
       
    }
};
