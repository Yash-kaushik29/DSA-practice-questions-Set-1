class Solution {
public:
    void solve(vector<int> nums, int index, vector<vector<int>>& ans) {
       
       // Base case
        if(index>=nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++) {
            swap(nums[i],nums[index]);
            solve(nums, index+1, ans);

            // Backtrack to reconstruct the original vector for further use.
            swap(nums[i],nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        solve(nums, 0, ans);
        return ans;
    }
};
