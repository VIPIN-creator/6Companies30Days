// https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/
// sol1 :- https://practice.geeksforgeeks.org/viewSol.php?subId=d8a1fcbb4a938ca592baff192b71d367&pid=705474&user=2019kucp1053 
// time complexity :- o(1)

int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here
        if((R2[1] > L1[1] || L2[1] < R1[1]) || (L2[0] > R1[0] || R2[0] < L1[0])) return 0;
        return 1;
    }
