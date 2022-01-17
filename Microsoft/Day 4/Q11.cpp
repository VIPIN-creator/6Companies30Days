// https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans; 
	string temp;
	int j;
	
	for(int i=1; i<=N; i++){
	    j = i;
	    temp.resize(0);
	    while(j){
	        if(j%2) temp.push_back('1');
	        else temp.push_back('0');
	        j = j/2;
	    }
	    reverse(temp.begin(), temp.end());
	    ans.push_back(temp);
	}
	
	return ans;
}
