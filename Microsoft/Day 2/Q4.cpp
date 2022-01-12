// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=b65d98292df0e2a9794285807a94bfff&pid=701264&user=2019kucp1053
int sx = 0, sy = 0, ex = r-1, ey = c-1, i = 0, j = 1, dx = 0, dy=1, k;
        
        vector<int> ans;
        ans.push_back(matrix[0][0]);
        for(k=0; k<r*c-1; k++){
            if(i==sx && j==sy){
                sy++; ey--;
                sx++;
                ex--;
                i = sx; j = sy;
                dx = 0; dy = 1;
            }
            if(j>ey){
                j = ey;
                i++;
                dx = 1; dy = 0;
            }
             if(i>ex){
                i = ex; 
                dx = 0; dy = -1;
                j--;
            }
             if(j<sy){
                j = sy;
                i--;
                dx = -1; dy = 0;
            }
            // cout << i << " " << j << endl;
            ans.push_back(matrix[i][j]);
            i += dx; j += dy;
        }
        
        
        return ans;
        
    }
