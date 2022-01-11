// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=e1351612ed9ed7528e0e2bb1d70e7699&pid=700281&user=2019kucp1053
// time :- o(n) space :- O(n)

void solve(Node* root, vector<int> &a){
        if(root == 0){
            a.push_back(0);
            return ;
        } 
        
        a.push_back(root->data);
        solve(root->left, a);
        solve(root->right, a);
        
        return ;
    }
    
    vector<int> serialize(Node *root) 
    {
        //Your code here
       vector<int> a;
       solve(root, a);
        return a;
        
    }
    
    int id = 0;
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if(id>=A.size() || A[id] == 0) {
        id++;
        return 0;
       }
       
       Node* p = new Node(A[id++]);
       p->left = deSerialize(A);
       p->right = deSerialize(A);
       
       return p;
       
    }
