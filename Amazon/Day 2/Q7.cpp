// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=ca24db599aa8d89b5e991e3042a091ba&pid=705333&user=2019kucp1053
// time :- o(26n) space :- o(26)
	string FirstNonRepeating(string A){
		    // Code here
		   queue<char> q;
		   vector<int> f(26, 0);
		   string ans; 
		   
		   for(auto x: A){
		      
		           f[x-'a']++;
		          if(f[x-'a'] == 1) q.push(x);
		     
		       
		       while(!q.empty()){
		           char c = q.front();
		           if(f[c-'a'] != 1) q.pop();
		           else break;
		       }
		       
		       if(!q.empty()){
		           ans.push_back(q.front());
		       }
		       else ans.push_back('#');
		       
		   }
		   
		   return ans;
		    
		}

// Sol 2:- https://practice.geeksforgeeks.org/viewSol.php?subId=d2742afb638d1ab3090558683fafb417&pid=705333&user=2019kucp1053
// time :- o(n) space:- o(26)
 struct Node{
	        int val;
	        Node* left = 0;
	        Node* right = 0;
	    };
	    
	    Node* head = 0, *tail = 0;
	    
	    Node* add(int x){
	        if(head == 0){
	            head = new Node();
	            head->val = x;
	            tail = head;
	           // cout << head;
	            return head;
	        }
	        
	        Node* p = new Node();
	        
	        p->val = x;
	        
	        tail->right = p;
	        p->left = tail;
	        tail = p;
	        
	        return tail;
	        
	    }
	    
	    void rmv(Node* p){
	        
	        if(p==head){
	            if(p->right){
    	            p->right->left = 0;
	            }
	            
	            head = head->right;
	           return ;
	        }
	        
	        if(tail == p) tail = tail->left;
	        
	        if(p->left){
	            p->left->right = p->right;
	        }
	        if(p->right){
	            p->right->left = p->left;
	        }
	        p->right = 0;
	        p->left = 0;
	        
	        return ;
	    }
	
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> fr(26, 0);
		    Node* adr[26];
		    
		    string ans;
		    
		    for(auto c : A){
		        fr[c-'a']++;
		        
		        if(fr[c-'a'] == 1){
		           adr[c-'a'] =  add(c-'a');
		          
		        }
		        else if(fr[c-'a'] == 2){
		            rmv(adr[c-'a']);
		        }
		        
                if(head)ans.push_back(head->val + 'a');
	            else ans.push_back('#');
		    }
		    
		    return ans;
		}
