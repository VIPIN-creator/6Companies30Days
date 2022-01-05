// https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1#
// sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=30cfc54491b467797453d10b8f30ce80&pid=704775&user=2019kucp1053
//  time :- o(n)
long long squaresInChessBoard(long long N) {
        // code here
      long long ans = 0;
      for(long long i=1; i<=N; i++ ){
        ans += (i*i);
          
      }
      
      return ans;
    }
