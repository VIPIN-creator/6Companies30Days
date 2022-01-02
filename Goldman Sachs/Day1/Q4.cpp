// https://practice.geeksforgeeks.org/problems/run-length-encoding/1/

// Sol 1: https://practice.geeksforgeeks.org/viewSol.php?subId=60d17af9ef5052e96e53b8819a3f8824&pid=700243&user=2019kucp1053
// time O(n)

string encode(string src)
{     
  //Your code here 
  int i=0, j = 0, n = src.size();
  string len;
  string ans;
  
  while(i<n){
    j = i;
    while(j<n && src[j] == src[i]) j++;
    
        ans.push_back(src[i]);
        len = to_string(j-i);
        for(auto c : len){
            ans.push_back(c);
        }
    
    i = j;
  }
  
  return ans;
}     
