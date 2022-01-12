// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=1e1ca94b85d0bcef8d6f0e5878618f0f&pid=701342&user=2019kucp1053
 vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       int i = n-1;
       stack<int> st;
    //   st.push(n-1);
       vector<int> ans(n, 1);
       
       while(i>=0){
           if(st.empty()){
               st.push(i);
               i--;
               continue;
           }
           
           if(price[st.top()] < price[i]){
               ans[st.top()] = st.top()-i;
               st.pop();
           }
           else{
               st.push(i);
               i--;
           }
           
       }
       
       while(!st.empty()){
           ans[st.top()] = st.top()+1;
           st.pop();
       }
       
       return ans;
       
    }
