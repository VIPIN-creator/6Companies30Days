// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/#
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=d2dcec60c8b590311c9e30c3c8b3397d&pid=701989&user=2019kucp1053

void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int i, j,n = matrix.size();
    
    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    
    for(j=0; j<n; j++){
        for(i=0; i<n/2; i++){
            swap(matrix[i][j], matrix[n-i-1][j]);
        }
    }
    
}
