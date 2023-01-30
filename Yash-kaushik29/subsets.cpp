class Solution {
public:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans) {
        
        // Base case
        if(index>=nums.size()) {
            ans.push_back(output);
            return;
        }

        //Exclude case
        solve(nums,output,index+1,ans);

        //Include case
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;

        solve(nums, output, 0, ans);
        return ans;
    }
};
