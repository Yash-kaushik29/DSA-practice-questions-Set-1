class Solution{
    public:
    //Complete this function
     void solve(string S, int index, vector<string>& ans) {
       
       // Base case
        if(index>=S.size()) {
            ans.push_back(S);
            return;
        }

        for(int i=index; i<S.size(); i++) {
            swap(S[i],S[index]);
            solve(S, index+1, ans);

            // Backtrack to reconstruct the original vector for further use.
            swap(S[i],S[index]);
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string> ans;

        solve(S, 0, ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
