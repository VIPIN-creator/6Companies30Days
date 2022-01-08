// https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1
// Sol :- https://practice.geeksforgeeks.org/viewSol.php?subId=990aff0f2381fabeeb734ae70bc069bd&pid=703024&user=2019kucp1053
void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    
	    char sign[9] = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};
	    
	    sort(nuts, nuts+n);
	    sort(bolts, bolts+n);
	    
	    for(int j=0; j<min(9, n); j++){
	        
	        if(nuts[j] == sign[j]) continue;
	        
    	    for(int i=j+1; i<min(n,9); i++){
    	        if(nuts[i] == sign[j]){
    	            swap(nuts[i], nuts[j]);
    	            swap(bolts[i], nuts[j]);
    	            break;
    	        }   
    	    }
	    }
	    
	}
