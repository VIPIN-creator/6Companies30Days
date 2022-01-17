// https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/
int solve(Node* root, int X, int &ans){
    if(root == 0) {
     return 0;
    }
    	
    int l = solve(root->left, X, ans);
    int r = solve(root->right, X, ans);
    	
    if(l+r+root->data == X){
        // cout << l << " " << r << " " << root->data << endl;
        ans++;
    }
    	
	return l+r+root->data;
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int ans = 0;
	solve(root, X, ans);
	return ans;
	
}
