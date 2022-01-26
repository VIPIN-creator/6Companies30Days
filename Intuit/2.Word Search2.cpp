bool vis[101][101];
    
     bool dfs(int id, int i, int j, vector<vector<char>>& board, string &word){
        if(id == word.size()-1){
            // cout << i << " " << j << endl;
            return 1;
        }
        
        vis[i][j] = 1;
        
        bool ans = 0;
        
        if(i < board.size()-1 && word[id+1] == board[i+1][j] && !vis[i+1][j])
            ans = ans || dfs(id+1, i+1, j, board, word);
            
        if(i >0 && word[id+1] == board[i-1][j] && !vis[i-1][j])
            ans = ans || dfs(id+1, i-1, j, board, word);
            
        if(j < board[0].size()-1 && word[id+1] == board[i][j+1] && !vis[i][j+1])
        ans = ans || dfs(id+1, i, j+1, board, word);
        
        if(j > 0 && word[id+1] == board[i][j-1] && !vis[i][j-1])
         ans = ans || dfs(id+1, i, j-1, board, word);
         
         vis[i][j] = 0;
         
         return ans;
        
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++)
            if(board[i][j] == word[0] ) if(dfs(0, i, j, board, word)) return 1;
        }
        
        return 0;
    }
