class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    int n=pow(2,s.length());
		    int x,j;
		    
		    for(int i=1; i<n; i++) {
		        x=i;
		        j=0;
		        string c="";
		        while(x) {
		            if(x&1)
		            c+=s[j];
		            j++;
		            x=x>>1;
		        }
		        ans.push_back(c);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
