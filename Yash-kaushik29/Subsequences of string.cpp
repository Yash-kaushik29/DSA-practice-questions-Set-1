#include <bits/stdc++.h> 

void solve(string str, string output, int index, vector<string>& ans) {

	// Base case
	if(index>=str.length()) {
		if(output.length()>0)  // to include the empty substring (" ")
		 {
			ans.push_back(output);
		 }
		return ;
	}

	//Exclude case
	solve(str,output,index+1,ans);

	//Include case
	char element=str[index];
	output.push_back(element);
	solve(str,output,index+1,ans);

}

vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> ans;
	string output="";
	solve(str, output, 0, ans);

	return ans;
	
}
