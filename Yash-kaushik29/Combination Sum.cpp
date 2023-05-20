class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp) {
        if(idx == candidates.size()) {
            if(target == 0) {
               ans.push_back(temp);
            }
            return ;
        }

        if(candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            solve(idx, candidates, target-candidates[idx], ans, temp);
            temp.pop_back();
        }
        solve(idx+1, candidates, target, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> temp;
        solve(0,candidates, target, ans, temp);

        return ans;
    }
};
