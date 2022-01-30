int solve(Node *node){
        if(node == 0) return 0;
        
        int l = solve(node->left);
        int r = solve(node->right);
        
        int x = node->data;
        
        node->data = l+r;
        
        return x+l+r;
        
        
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
