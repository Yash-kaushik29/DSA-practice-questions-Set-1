class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<int>q;
		    map<char,int>m;
		    string ans="";
		    for(int i=0;i<A.size();i++){
		        m[A[i]]++;
		        if(m[A[i]]==1){
		            q.push(A[i]);
		            ans.push_back(q.front());
		        }else{
		            while(!q.empty() && m[q.front()]>1) q.pop();
		            if(q.empty()) ans.push_back('#');
		            else ans.push_back(q.front());
		        }
		    }
		    return ans;
		}

};
