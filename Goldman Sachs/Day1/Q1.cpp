// Given an array of strings, return all groups of strings that are anagrams.
// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/

// Sol 1. :- https://practice.geeksforgeeks.org/viewSol.php?subId=3847b68b901b468507a1c8db23857198&pid=701966&user=2019kucp1053
// time complexity:- o(n*n*mlogm)
vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        string t, r;
        vector<vector<string>> ans;
        vector<string> temp;
        vector<bool> mark(n, 0);
        
        for(int i=0; i<n; i++){
            if(mark[i]) continue;
            
            temp.push_back(string_list[i]);
            mark[i] = 1;
            r = string_list[i];
            sort(r.begin(), r.end());
            
            for(int j=i+1; j<n; j++){
                t = string_list[j];
                sort(t.begin(), t.end());
                if(r != t) continue;
                
                mark[j] = 1;
                temp.push_back(string_list[j]);
                
            }
            ans.push_back(temp);
            temp.resize(0);
        }
        
        return ans;
        
    }
    

// Sol 2 :- https://practice.geeksforgeeks.org/viewSol.php?subId=fb7d9667d683206876a36c62ed9b6317&pid=701966&user=2019kucp1053
// time complexity :- o(n*mlogm)
 vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        
        map<string, vector<string>> mp;
        
        string t;
        
        for(auto x : string_list){
            t = x;
            sort(t.begin(), t.end());
            mp[t].push_back(x);
        }
        
        vector<vector<string>> ans;
        
        for(auto s: mp){
            ans.push_back(s.second);
        }
    
        
        return ans;
        
    }

// Sol 3:- https://practice.geeksforgeeks.org/viewSol.php?subId=e7e93ed491bc22599cff223d2768ab89&pid=701966&user=2019kucp1053
// time complexity :- o(n*m)
vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        
       
        map<map<char,int>, vector<string>> mp2;
        
        string t;
        
        for(auto x : string_list){
            map<char, int> mp;
             
            for(auto c : x) mp[c]++;
           
            mp2[mp].push_back(x);
        }
        
        vector<vector<string>> ans;
        
        for(auto s: mp2){
            ans.push_back(s.second);
        }
    
        
        return ans;
        
    }
