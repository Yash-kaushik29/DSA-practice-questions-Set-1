// Method 1: using heap

int n = nums.size();
        unordered_map<int, int> map;
        for(auto i : nums){
            map[i]++;
        }
        int ans = 0;
        for(auto x : map){
            // if k == 0 instead of checking x.first+k check its frequency
            if(k == 0){
                if(x.second > 1){
                    ans++;
                }
            }else if(map.find(x.first+k) != map.end()){
                    ans++;
            }
        }
        return ans;
 }

// Method 2: using two pointers

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, i = 0, j = 1;
        for(i, j; i<nums.size() && j<nums.size(); ) {
            if(i==j || nums[j]-nums[i]<k) j++;
            else {
                if(nums[j]-nums[i]==k) {
                    ans++;
                    j++;
                    while(j<nums.size() && nums[j]==nums[j-1]) j++; // remove redundant
                }
                i++;
                while(i<j && nums[i]==nums[i-1]) i++; // remove redundant
            }
        }
        return ans;
    }
};
