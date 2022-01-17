// // https://practice.geeksforgeeks.org/problems/phone-directory4628/1/#
class TrieNode{
    public:
  TrieNode* next[26];
  bool isEnd;
  
  TrieNode(){
      memset(next, 0, sizeof(next));
      isEnd = 0;
  }
  
};

class Trie{
    public:
    
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string s){
        TrieNode* p = root;
        for(int i=0; i<s.length(); i++){
            if(!p->next[s[i]-'a']) p->next[s[i]-'a'] = new TrieNode();
            p = p->next[s[i]-'a'];
        }
        p->isEnd = 1;
        
        return ;
    }
    
    vector<string> prefix(TrieNode*p, string temp, vector<string> &ans){
       
        vector<string> temp2;
        
        if(p->isEnd == 1) 
           ans.push_back(temp);
        
  
        for(int i=0; i<26; i++){
            if(!p->next[i]) continue;
            temp.push_back(i+'a');
            temp2 = (prefix(p->next[i], temp, ans));
            temp.pop_back();
        }
        
        return ans;
    }
    
    vector<string> search(string s){
        TrieNode*p = root;
        vector<string> ans, temp2;
        
        //  check if this substring is present in trie or not if not the return empty string
        for(int i=0; i<s.length(); i++){
            if(!p->next[s[i]-'a']) return {"0"};
            p = p->next[s[i]-'a'];
        }
        
        // if this substring was an end (also present as a word alone) then add to answer
        if(p->isEnd) ans.push_back(s);
        
        string temp;

        for(int i=0; i<26; i++){
            if(!p->next[i]) continue;
        
        // for that substring s add all the strings who have prefix s. 
            temp.push_back(i+'a');
            prefix(p->next[i], temp, temp2);
           
            temp.resize(0);
        }
       
        // append to all the strings the prefix. 
        for(auto &c : temp2){
            c = s+c;
        }
        
        ans.insert(ans.end(), temp2.begin(), temp2.end());
       
        return ans;
    }
    
};

class Solution{
public:


    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie *p = new Trie();
        for(int i=0; i<n; i++)
            p->insert(contact[i]);
            
        vector<vector<string>> ans;    
        
     
        // for every substring call search fun
        for(int i=0; i<s.length(); i++){
            ans.push_back(p->search(s.substr(0, i+1)));
        }
        
        return ans;
        
    }
};
