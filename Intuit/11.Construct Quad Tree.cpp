  Node* solve(int i, int j, int n, vector<vector<int>>& grid){
        if(n==1){
            Node* p  = new Node(grid[i][j], 1);
            return p;
        }
        int l ,r;
        for( l = i; l<i+n; l++){
            for( r=j; r<j+n; r++){
                if(grid[l][r] != grid[i][j]) break;
            }
            if(r<j+n) break;
        }
        
        if(l == i+n){
            Node* p = new Node(grid[i][j], 1);
            return p;
        }
        
        Node* p = new Node(0, 0);
        p->topLeft = solve(i, j, n/2, grid);
        p->topRight = solve(i, j+(n/2), n/2, grid);
        p->bottomLeft = solve(i+n/2, j, n/2, grid);
        p->bottomRight = solve(i+n/2, j+n/2, n/2, grid);

        return p;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(0,0, grid.size(), grid); 
    }
