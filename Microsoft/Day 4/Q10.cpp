// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/  
 int FindMaxSum(int arr[], int n)
    {
        // Your code here
        arr[1] = max(arr[0], arr[1]);
        for(int i=2; i<n; i++){
            arr[i] = max(arr[i]+arr[i-2], arr[i-1]);
        }
        
        return arr[n-1];
    }
