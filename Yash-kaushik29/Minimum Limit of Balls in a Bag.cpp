class Solution {
public:
    bool isPossible(vector<int> nums, int o, int penalty) {
        int ops=0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > penalty) {
                if(nums[i] % penalty == 0) {
                    ops += nums[i] / penalty - 1;
                } else {
                    ops += nums[i] / penalty;
                }
                if(ops > o) return false;
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int o) {
        int r = *max_element(nums.begin(), nums.end());
        int l = 1;
        int res = r;
        while(l <= r) {
            int penalty = (l + r) / 2;
            
            if(isPossible(nums, o, penalty)) {
                res = penalty;
                r = penalty-1;
            }
            
            else {
                l = penalty + 1;
            }
        }
        return res;
    }
};
