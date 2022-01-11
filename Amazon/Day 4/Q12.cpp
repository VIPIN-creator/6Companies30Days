// https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=d499395927978d3bb52f86d6308f0996&pid=702959&user=2019kucp1053
// time :- O(log26) space:- o(1)
string colName (long long int n)
    {
        // your code here
      string ans;
      int rem = 0;
      
      while(n>0){
         if(n%26)ans.push_back(n%26 + 'A' - 1);
         else ans.push_back('Z');
         n = n/26;
      }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
