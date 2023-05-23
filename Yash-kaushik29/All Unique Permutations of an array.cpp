class Solution {
  public:
    void solve(int idx, int n, vector<int> arr, vector<vector<int>>& ans) {
        if(idx >= n) {
            ans.push_back(arr);
            return ;
        }
        
        for(int i=idx; i<n; i++) {
            swap(arr[i], arr[idx]);
            solve(idx+1, n, arr, ans);
            
            // backtarck
            swap(arr[i], arr[idx]);
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        vector<vector<int>> ans;
        solve(0, n, arr, ans);
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};
