// https://practice.geeksforgeeks.org/problems/burning-tree/1/
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=9657a46222d03114616a9bfad27100be&pid=702131&user=2019kucp1053
// time:- O(N) Space :- O(N)

  int ans = 0;
map<int, int> mp;

int solve2(Node* root){
    if(root == 0) return 0;
    
    ans = max(ans, mp[root->data]);
    
    if(root->left){
        if(mp.find(root->left->data) == mp.end()){
            mp[root->left->data] = mp[root->data]+1;
        }
    }
    if(root->right){
        if(mp.find(root->right->data) == mp.end()){
            mp[root->right->data] = mp[root->data]+1;
        }
    }
    
    solve2(root->left);
    solve2(root->right);
    
    return ans;
}

int solve(Node* root, int start, bool flag, int val){
    if(root == 0) return -1;
    int curr = 0;
    
    if(flag == 0){
        if(root->data == start){
            flag = 1;
            curr = 0;
   		 }
    
    int ans1 = solve(root->left, start, flag, 0);
    
    if(flag == 0 && ans1 != -1){ 
        curr = ans1+1;  
        flag = 1;
    }
  
        
    int ans2 = solve(root->right, start, flag, curr);
    
    if(flag == 0 && ans2!=-1) {
        curr = ans2+1;
        flag = 1;
    }
   	
    if(flag) mp[root->data] = curr;    
     
    if(flag) return curr;
    return -1;
    }  
   
    mp[root->data] = val+1;
    solve(root->left, start, flag, val+1);
    solve(root->right, start, flag, val+1);

    return val+1;
}
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        bool flag = 0;
        solve( root, target, flag, 0);
        return solve2(root);
    }
