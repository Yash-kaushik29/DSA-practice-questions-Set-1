class Solution {
    int n;
public:
    bool solve(int i, int currSum, int reqSum, int k, vector<int>& nums, vector<int>& alreadyPicked) {
        
        if(k==1) return true;
        
        if(i >= n) return false;
        if(currSum > reqSum) return false;
        
        if(currSum == reqSum) {
            return solve(0, 0, reqSum, k-1, nums, alreadyPicked);
        }
        
        
        if(alreadyPicked[i] == 1) {
            return solve(i+1, currSum, reqSum, k, nums, alreadyPicked);
        }
        else {
            // Pick
            currSum+=nums[i];
            alreadyPicked[i]=1;
            bool op1 = solve(i+1, currSum, reqSum, k, nums, alreadyPicked);
            
            // Skip
            currSum-=nums[i];
            alreadyPicked[i]=0;
            bool op2 = solve(i+1, currSum, reqSum, k, nums, alreadyPicked);
            
            return op1 or op2;
        }
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        vector<int> alreadyPicked(n,0);
        int sum=0;
         
        for(int i=0; i<n; i++) {
            sum+=nums[i];
        }
        if(n<k || sum%k) return false;
         
        int reqSum = sum/k;
        return solve(0, 0, reqSum, k, nums, alreadyPicked);
    }
};
