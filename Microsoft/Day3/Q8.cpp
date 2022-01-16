void connect(Node *root)
    {
       // Your Code Here
       if(root == 0) return ;
       if(root->left){
           root->left->nextRight = root->right;
       }
       if(root->nextRight){
           if(root->right){
               if(root->nextRight->left)
               root->right->nextRight = root->nextRight->left;
               else  root->right->nextRight = root->nextRight->right;
           }
           else if(root->left) {
                if(root->nextRight->left)
               root->left->nextRight = root->nextRight->left;
               else  root->left->nextRight = root->nextRight->right;
           }
       }
       
       connect(root->left);
       connect(root->right);
    } 
