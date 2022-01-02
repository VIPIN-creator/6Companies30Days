// https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/

// Sol 1:- https://practice.geeksforgeeks.org/viewSol.php?subId=32f74be0eb5b56993b22df930ed85fe8&pid=704216&user=2019kucp1053
//  time:- o(1)

int findPosition(int N , int M , int K) {
        // code here
        return (K-1 + M)%N == 0 ? N :  (K-1 + M)%N;
    }
