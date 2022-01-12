// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/#
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=9c0957d37c3dff969358c4ef21ca0826&pid=701199&user=2019kucp1053
    vector<string> ans;   
    
  char numpad[10] = {'-', '-', 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};
    
    void solve(int i, int a[], int N, string temp){
        if(i==N){
            ans.push_back(temp);
            return ;
        }
        
        for(int j=0; j<3; j++){
            solve(i+1, a, N, temp+string(1,numpad[a[i]]+j));
        }
        
        if(a[i] == 9 || a[i] == 7){
            solve(i+1, a, N, temp+string(1,numpad[a[i]]+3));
        }
        
        return;
        
    }
  
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        string temp;
        solve(0, a, N, temp);
        return ans;
    }
