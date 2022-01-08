// https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=6bc4bcd76619b5cf9e8008686b18bcd4&pid=705293&user=2019kucp1053
int isValid(vector<vector<int>> mat){
        // code here
        
        
        for(int i=0; i<9; i++){
            vector<int> fr1(10, 0), fr2(10, 0);
            for(int j=0; j<9; j++){
                fr1[mat[i][j]]++;
                fr2[mat[j][i]]++;
            }
            
            for(int k=1; k<10; k++){
                if(fr1[k]>1 || fr2[k]>1) return 0;
            }
            
        }
        
        for(int i=0; i<7; i+=3){
            
            for(int j=0; j<7; j+=3){
                vector<int> fr(10, 0);
                
                for(int k=i; k<i+3; k++){
                   for(int l = j; l<j+3; l++) fr[mat[k][l]]++;
                //   cout << endl;
                }
                
                for(int k=1; k<10; k++){
                    if(fr[k]>1) return 0;
                }
                
            }
        }
        
        return 1;
        
        
    }
