class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> mp;
		    queue<char> q;
		    string ans="";
		    
		    for(int i=0; i<A.size(); i++) {
		        char ch=A[i];
		        
		        // increase count
		        mp[ch]++;
		        // push in queue
		        q.push(ch);
		        
		        while(!q.empty()) {
		            //repeating character
		            if(mp[q.front()] > 1)
		              q.pop();
		              
		            //non-repeating character
		            else {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        //Non-repeating character is not present in queue
		        if(q.empty()) {
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};
